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

    $ hg clone ssh://hg@bitbucket.org/petar/pjisp-zbirka-zadataka
    $ cd pjisp-zbirka-zadataka
    $ pipenv install


Quick start
===========

Show help::

    $ pipenv run fab

You can also run the following command to automatically (re)build the book
whenever its files are updated::

    find -regextype posix-extended -regex ".*\.(rst|py|c)" | entr -c pipenv run fab build

Using Docker
------------

Build the Docker image::

    $ docker build --tag petarmaric/pjisp-zbirka-zadataka .

Show help::

    $ docker run --rm -it --user="$(id -u):$(id -g)" --net=none --volume="$PWD":/app petarmaric/pjisp-zbirka-zadataka


Contribute
==========

If you find any bugs, or wish to propose new features `please let us know`_.

If you'd like to contribute, simply fork `the repository`_, commit your changes
and send a pull request. Make sure you add yourself to `CONTRIBUTORS`_.

.. _`please let us know`: https://bitbucket.org/petar/pjisp-zbirka-zadataka/issues/new
.. _`the repository`: http://bitbucket.org/petar/pjisp-zbirka-zadataka
.. _`CONTRIBUTORS`: https://bitbucket.org/petar/pjisp-zbirka-zadataka/src/default/CONTRIBUTORS
