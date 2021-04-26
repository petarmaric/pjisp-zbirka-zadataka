Objekti koji dobijaju električnu energiju iz trafo stanice nalaze se u ulaznoj datoteci ``trafo-stanica.txt``. 

Objekat je predstavljen na sledeći način:

* ulica (jedna reč, maksimalno 20 karaktera)
* broj (neoznačeni, ceo broj)
* broj domaćinstava (neoznačeni, ceo broj)
* tip objekta (jedna reč, maksimalno 10 karaktera)
* prijavljen kvar (jedna reč, maksimalno 2 karaktera)

Učitati objekte iz ulazne datoteke, čije je ime zadato kao drugi argument komandne linije i uraditi sledeće:

a) Pronaći sve objekte koji imaju prijavljen kvar.
   Izračunati ukupan broj domaćinstava koja su trenutno bez električne energije.
   Informacije o objektima i ukupan broj domaćinstava ispisati u izlaznu datoteku sa imenom zadatim kao treći argument komandne linije.
   Prilikom ispisa, za stringove koristiti ``%s``, a za neoznačene vrednosti ``%2u`` format specifikator.
b) Uporediti broj objekata trenutno zahvaćenih nestankom električne energije sa vrednošću prvog argumenta komandne linije.
   Ukoliko broj objekata premašuje zadatu vrednost, u istu izlaznu datoteku iz prethodne tačke napisati: "Moguć kvar trafo stanice!".
   
Vrednost prvog argumenta komandne linije mora biti prirodan broj, veći od 1.

U slučaju prevremenog završetka programa, kodovi grešaka su sledeći:

* Ako poziv programa ima nedovoljan ili suvišan broj argumenata, izaći iz programa sa kodom greške ``1`` (``EXIT_FAILURE``).
* Ako vrednost argumenta ne zadovoljava zadati uslov, izaći iz programa sa kodom greške ``2``.
* Ako nije moguće otvoriti ulaznu datoteku, izaći iz programa sa kodom greške ``3``.
* Ako nije moguće otvoriti izlaznu datoteku, izaći iz programa sa kodom greške ``4``.

Primer ulazne datoteke ``trafo-stanica.txt``:

.. literalinclude:: trafo-stanica.txt

Primer poziva programa:

.. code-block:: bash

  ./prijava_kvarova 5 trafo-stanica.txt bez-energije.txt

Primer izlazne datoteke ``bez-energije.txt``:

.. literalinclude:: bez-energije-5.txt

Primer poziva programa:

.. code-block:: bash

  ./prijava_kvarova 7 trafo-stanica.txt bez-energije.txt

Primer izlazne datoteke ``bez-energije.txt``:

.. literalinclude:: bez-energije-7.txt


