U ulaznom fajlu ``letovi.txt`` redom su navedeni podaci o letovima.

Let je predstavljen sledećim podacima:

* ID leta (jedna reč, maksimalno 10 karaktera)
* oznaka aerodroma mesta polaska (jedna reč, maksimalno 3 karaktera)
* oznaka aerodroma mesta dolaska (jedna reč, maksimalno 3 karaktera)
* dužina leta u km (prirodna vrednost)
* broj_presedanja (prirodna vrednost)


Učitati letove iz ulazne datoteke u statički niz.


Cena leta računa se na sledeći način:

* Svako presedanje smanjuje cenu leta za 5€
* Dužina leta manja od 5000km --> 1km = 0,5€
* Dužina leta između 5000km i 10000km (>= 5000km, < 10000km)  --> 1km = 0.75€
* Dužina leta veća ili jednaka 10000km --> 1km = 1€

U izlaznu datoteku ispisati ID, oznaku aerodroma mesta polaska i cenu svih letova ka x aerodromu (x je zadat kao argument komandne linije).
Ukoliko ne postoji nijedan let ka zadatom aerodromu u izlaznu datoteku ispisati: "Nema letova ka zadatom aerodromu!".

Naziv izlazne datoteke formirati tako da bude ``letovi_ka_<x>.txt``.


Primer ulazne datoteke:

.. literalinclude:: letovi.txt
	 
Primer poziva programa:

.. code-block:: bash

  ./let letovi.txt VIE

Primer izlazne datoteke ``letovi_ka_VIE.txt``:

.. literalinclude:: letovi_ka_VIE.txt

.. raw:: pdf

  PageBreak

Primer poziva programa:

.. code-block:: bash

  ./let letovi.txt LAX

Primer izlazne datoteke ``letovi_ka_LAX.txt``:

.. literalinclude:: letovi_ka_LAX.txt

