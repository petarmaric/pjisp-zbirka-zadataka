import fnmatch
import os
import shutil

from fabric.api import local, task


SPHINX_SOURCE_DIR = '.'
SPHINX_BUILD_DIR = '_build'

SPHINX_BUILDERS = [
    'html',
    'singlehtml',
]

LATEX_BUILD_DIR = 'pdf'


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


@task(default=True)
def rebuild_all():
    clean()

    for builder_name in SPHINX_BUILDERS:
        sphinx_build(builder_name)

    build_books()
