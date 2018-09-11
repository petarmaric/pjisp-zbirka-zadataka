import codecs
from datetime import date
import locale
import os
import sys

from fabric.api import abort, prompt, task
from jinja2 import Environment, FileSystemLoader


VALID_SMEROVI = 'E1, EM, PSI, RA'.split(', ')
VALID_KOLOKVIJUMI = 'T12, T34, T5, TP'.split(', ')
MAX_GRUPA = 9
MAX_GRUPA_STARI_STUDENTI = 4
VALID_GRUPE = ["G%d" % x for x in xrange(1, MAX_GRUPA+1)] + \
              ["S%d" % x for x in xrange(1, MAX_GRUPA_STARI_STUDENTI+1)]
AUTHORS_LIST = [line.strip() for line in codecs.open('AUTHORS', 'r', 'utf-8')]

ZADACI_BASE_DIR = 'zadaci'
ZADACI_SA_KOLOKVIJUMA_DIR = os.path.join(ZADACI_BASE_DIR, 'sa-kolokvijuma')


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
        text="%s (%s)? " % (question, ', '.join(choices).encode('utf-8')),
        validate=validate_choice(choices, coerce)
    )

def validate_author(author):
    matches = [x for x in AUTHORS_LIST if x.lower().startswith(author.lower())]

    num_matches = len(matches)
    if num_matches == 0:
        raise ValueError("No authors found that start with '%s'" % author)
    if num_matches > 1:
        raise ValueError("Multiple matching authors found (%s)" % ', '.join(matches))

    return matches[0]

@task
def sa_kolokvijuma():
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
    autor = prompt_choice('Ko je autor zadatka', AUTHORS_LIST, validate_author)

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
            'naziv': naziv.decode(sys.stdin.encoding or locale.getpreferredencoding(True)), # based on http://stackoverflow.com/a/477496
            'autor': autor,
            'zadatak_dir': zadatak_dir.replace('\\', '/'),
        }).dump(os.path.join(zadatak_dir, filename), encoding='utf-8')

    for filename in ['zadatak.rst', 'resenje.c', 'index.rst']:
        print "\tPravim template datoteku '%s'..." % filename,
        create_file_from_template(filename)
        print 'OK!'

    print """
Sve potrebne datoteke su smestene u direktorijum '%s'.

Molim Vas unesite Vas sadrzaj u datoteke 'zadatak.rst' i 'resenje.c', postujuci dogovorene konvencije.
Molim Vas ukljucite i sve potrebne ulazne i (generisane) izlazne datoteke ako ih 'resenje.c' koristi.

Molim Vas da u datoteci 'index.rst' odaberete kategorije koje blize opisuju tematiku Vaseg zadatka.
Ukoliko smatrate da Vam je potrebna nova kategorija, prvo se obratite Vasoj kontakt osobi:
    Petar Maric <petarmaric@uns.ac.rs>

Ukoliko je to potrebno (i tacno znate sta radite) mozete napraviti i dodatne izmene u datoteci 'index.rst'.

OBAVEZNO temeljno testirajte 'resenje.c'!

Celokupnu knjigu potom mozete ponovo kompajlirati pozivom komande 'fab build'.
""" % zadatak_dir
