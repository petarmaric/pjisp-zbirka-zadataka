import fnmatch
import os
import shutil

from fabric.api import env, local, task


SPHINX_SOURCE_DIR = '.'
SPHINX_BUILD_DIR = '_build'

SPHINX_BUILDERS = [
    'html',
    'singlehtml',
    'text',
]


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
    env.is_miktex = is_miktex()
    
    base_dir = os.getcwd()
    os.chdir(os.path.join(SPHINX_BUILD_DIR, 'latex'))
    for filename in fnmatch.filter(os.listdir('.'), '*.tex'):
        pdflatex(filename)
        makeindex(filename)
        pdflatex(filename)
        pdflatex(filename)
    
    os.chdir(base_dir)
    print "Build finished; the PDF files are in %s." % os.path.join(SPHINX_BUILD_DIR, 'latex')

def is_miktex():
    return 'MiKTeX' in local('pdflatex -version', capture=True)

def pdflatex(filename):
    local("pdflatex %(be_quiet)s -interaction=nonstopmode -halt-on-error %(filename)s" % {
        'filename': filename,
        'be_quiet': '-quiet' if env.is_miktex else '' # TexLive (used by Ubuntu) doesn't support the '-quiet' CLI flag
    })

def makeindex(filename):
    local("makeindex -q %s.idx" % os.path.splitext(filename)[0])


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
