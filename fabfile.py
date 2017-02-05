from datetime import date
import fnmatch
import os
import shutil

from fabric.api import abort, local, prompt, task
from jinja2 import Environment, FileSystemLoader


VALID_SMEROVI = 'E1, PSI, RA'.split(', ')
VALID_KOLOKVIJUMI = 'T12, T34, T5, TP'.split(', ')
MAX_GRUPA = 9
VALID_GRUPE = ["G%d" % x for x in xrange(1, MAX_GRUPA+1)]

ZADACI_BASE_DIR = 'zadaci'
ZADACI_SA_KOLOKVIJUMA_DIR = os.path.join(ZADACI_BASE_DIR, 'sa-kolokvijuma')

SPHINX_SOURCE_DIR = '.'
SPHINX_BUILD_DIR = '_build'

SPHINX_BUILDERS = [
    'html',
    'singlehtml',
    'text',
]

LATEX_BUILD_DIR = 'pdf'


def validate_choice(choices, coerce=None):
    def validate(x):
        if callable(coerce):
            x = coerce(x)
        
        if x not in choices:
            raise ValueError("%s is not a valid choice" % x)
        return x
    
    return validate

def prompt_choice(question, choices, coerce=None):
    return prompt(
        text="%s (%s)? " % (question, ', '.join(choices)),
        validate=validate_choice(choices, coerce)
    )

@task
def novi_zadatak_sa_kolokvijuma():
    today = date.today()
    skolska_godina = today.year
    if today.month < 10: # Smatraj da tek od oktobra pocinje nova skolska godina
        skolska_godina -= 1
    
    print 'Molim Vas odgovorite na narednih nekoliko pitanja da bismo Vam pomogli da dodate novi zadatak sa kolokvijuma.\n'

    skolska_godina = str(prompt('Koje skolske godine se radio kolokvijum?', default=skolska_godina, validate=int))
    smer = prompt_choice('Koji smer', VALID_SMEROVI, str.upper)
    kolokvijum = prompt_choice('Koji kolokvijum', VALID_KOLOKVIJUMI, str.upper)
    grupa = prompt_choice('Koja grupa', VALID_GRUPE, str.upper)
    naziv = prompt('Unesite kratak i opisan naziv zadatka:')
    
    print '\nPravim zadatak:'

    zadatak_dir = os.path.join(ZADACI_SA_KOLOKVIJUMA_DIR, skolska_godina, smer, kolokvijum, grupa)
    print "\tPravim novi direktorijum '%s'..." % zadatak_dir,
    if os.path.exists(zadatak_dir):
        abort("Directory '%s' already exists!" % zadatak_dir)
    os.makedirs(zadatak_dir)
    print 'OK!'

    env = Environment(loader=FileSystemLoader('_templates/zadaci/sa-kolokvijuma'), keep_trailing_newline=True)
    def create_file_from_template(filename):
        env.get_template(filename).stream({
            'naziv': naziv,
            'zadatak_dir': zadatak_dir.replace('\\', '/'),
        }).dump(os.path.join(zadatak_dir, filename), encoding='utf-8')
    
    for filename in ['zadatak.rst', 'resenje.c', 'index.rst']:
        print "\tPravim template datoteku '%s'..." % filename,
        create_file_from_template(filename)
        print 'OK!'

    print """
Sve potrebne datoteke su smestene u direktorijum '%s'.

Molim Vas izmenite datoteke 'zadatak.rst' i 'resenje.c', postujuci dogovorene konvencije.
Ukoliko je to potrebno (i tacno znate sta radite) mozete izmeniti i datoteku 'index.rst'.

Celokupnu knjigu potom mozete ponovo kompajlirati pozivom komande 'fab'.
""" % zadatak_dir


@task
def clean():
    if os.path.exists(SPHINX_BUILD_DIR):
        print "Directory '%s' already exists and will be deleted before continuing" % SPHINX_BUILD_DIR
        shutil.rmtree(SPHINX_BUILD_DIR)
        print
        print

    os.mkdir(SPHINX_BUILD_DIR)


@task
def sphinx_build(builder_name):
    print "Building %s..." % builder_name
    local("sphinx-build -M %s %s %s" % (builder_name, SPHINX_SOURCE_DIR, SPHINX_BUILD_DIR))
    print
    print
    print


@task
def build_books():
    sphinx_build('latex')

    print 'Building books...'
    os.chdir(os.path.join(SPHINX_BUILD_DIR, 'latex'))
    for filename in fnmatch.filter(os.listdir('.'), '*.tex'):
        pdflatex(filename)
        pdflatex(filename)
    print "Build finished; the PDF files are in %s\latex\%s." % (SPHINX_BUILD_DIR, LATEX_BUILD_DIR)

def pdflatex(filename):
    local("pdflatex -quiet -aux-directory=%(build_dir)s -output-directory=%(build_dir)s -interaction=nonstopmode -halt-on-error %(filename)s" % {
        'build_dir': LATEX_BUILD_DIR,
        'filename': filename,
    })


@task
def lint():
    sphinx_build('lint')


@task(default=True)
def rebuild_all():
    clean()

    lint()

    for builder_name in SPHINX_BUILDERS:
        sphinx_build(builder_name)

    build_books()
