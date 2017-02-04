# -*- coding: utf-8 -*-
#
# PJISP zbirka zadataka documentation build configuration file, created by
# sphinx-quickstart on Sat Jan 14 21:29:28 2017.
#
# This file is execfile()d with the current directory set to its
# containing dir.
#
# Note that not all possible configuration values are present in this
# autogenerated file.
#
# All configuration values have a default; values that are commented out
# serve to show the default.

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os
import sys
sys.path.insert(0, os.path.abspath('_ext'))


# -- General configuration ------------------------------------------------

# If your documentation needs a minimal Sphinx version, state it here.
#
# needs_sphinx = '1.0'

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    'sphinx.ext.mathjax',
    'extra_texescape',
    'lint',
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# The suffix(es) of source filenames.
# You can specify multiple suffix as a list of string:
#
# source_suffix = ['.rst', '.md']
source_suffix = '.rst'

# The master toctree document.
master_doc = 'zbirka'

# General information about the project.
import codecs
with codecs.open('AUTHORS', 'r', 'utf-8') as fp:
    authors_list = [line.split(' <')[0] for line in fp]
    authors_str = u', '.join(authors_list)
author = authors_str

project = u'PJISP zbirka zadataka'
copyright = u'2017, ' + author

# The version info for the project you're documenting, acts as replacement for
# |version| and |release|, also used in various other places throughout the
# built documents.
#
# The short X.Y version.
version = u''
# The full version, including alpha/beta/rc tags.
release = u''

# The language for content autogenerated by Sphinx. Refer to documentation
# for a list of supported languages.
#
# This is also used if you do content translation via gettext catalogs.
# Usually you set "language" from the command line for these cases.
language = 'sr_Latn'

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This patterns also effect to html_static_path and html_extra_path
exclude_patterns = [
    '_build', 'Thumbs.db', '.DS_Store',
    'TODO.rst', 'README.rst', '**/zadatak.rst'
]

# The default programming language to highlight source code in.
highlight_language = 'guess'

# The name of the Pygments (syntax highlighting) style to use.
pygments_style = 'trac'

# If true, `todo` and `todoList` produce output, else they produce nothing.
todo_include_todos = False


# -- Options for HTML output ----------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'classic'

# Theme options are theme-specific and customize the look and feel of a theme
# further.  For a list of options available for each theme, see the
# documentation.
#
html_theme_options = {
    'collapsiblesidebar': True,
}

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']


# -- Options for LaTeX output ---------------------------------------------

latex_elements = {
    'papersize': 'b5paper',
    'pointsize': '10pt',

    'geometry': r'\usepackage[papersize={165mm,235mm}, margin=20mm]{geometry}',

    # Latex figure (float) alignment
    #
    # 'figure_align': 'htbp',

    'preamble': r'\fvset{fontsize=\scriptsize}',
}

# Grouping the document tree into LaTeX files. List of tuples
# (source start file, target name, title,
#  author, documentclass [howto, manual, or own class]).
latex_documents = [
    (master_doc, 'zbirka.tex', u'PJISP zbirka zadataka',
     author, 'manual'),
]
