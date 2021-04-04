About
=====

The `PJISP course`_ problem book that makes coursework easier for our `ACS`_
students.

.. _`PJISP course`: http://www.acs.uns.ac.rs/sr/pjisp
.. _`ACS`: http://www.acs.uns.ac.rs/

Instructions for ACS students
-----------------------------

If you just want to read this book you can either buy its printed edition or
`access it online for free`_.

.. _`access it online for free`: http://pjisp.petarmaric.com/zbirka-zadataka


Installation
============

This project doesn't require system wide installation, just clone its repository
to get started::

    $ git clone https://github.com/petarmaric/pjisp-zbirka-zadataka.git
    $ cd pjisp-zbirka-zadataka
    $ pipenv install


Quick start
===========

Show help::

    $ pipenv run fab help

You can also run the following command to automatically (re)build the book
whenever its files are updated::

    find -regextype posix-extended -regex ".*\.(rst|py|c)" | entr -c pipenv run fab build

Using Docker
------------

If you do not wish to install a LaTeX distribution on your system you can build
your local Docker image::

    $ docker build --tag petarmaric/pjisp-zbirka-zadataka .

and then use the dockerized version instead::

    $ ./dockerized.sh help
    [pjisp.petarmaric.com] Executing task 'help'
    Pregled korisnih Fabric komandi:

    * 'build'                         kompajlira celokupnu knjigu (u svim podrzanim formatima)
    * 'novi_zadatak.sa_kolokvijuma'   dodaje novi zadatak sa kolokvijuma

    Available commands:

        help
        build
        build.build_books
        build.clean
        build.lint
        build.rebuild_all
        build.sphinx_build
        novi_zadatak.sa_kolokvijuma
        publish
        publish.html


Contribute
==========

If you find any bugs, or wish to propose new features `please let us know`_.

If you'd like to contribute, simply fork `the repository`_, add yourself to
``CONTRIBUTORS`` (following the same format as used in ``AUTHORS``), commit
your changes and send a pull request.

.. _`please let us know`: https://github.com/petarmaric/pjisp-zbirka-zadataka/issues/new
.. _`the repository`: https://github.com/petarmaric/pjisp-zbirka-zadataka
