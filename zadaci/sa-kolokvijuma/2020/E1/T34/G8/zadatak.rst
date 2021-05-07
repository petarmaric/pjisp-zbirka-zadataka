

Iz zadate ulazne datoteke ``autobusi.txt`` učitati statički niz
struktura, pri čemu se struktura ``autobus_st`` sastoji od sledećih polja:

- prevoznik (jedna reč, maksimalno 30 karaktera),
- stanje (jedna reč, maksimalno 10 karaktera),
- cena_karte (realan broj) i
- broj_mesta (prirodan broj).

Na osnovu parametara ``traženi_prevoznik`` i ``prijavljeno_putnika`` koji
se prihvataju preko standardnog ulaza, proveriti da li autobusi
traženog prevoznika mogu da prevezu sve prijavljene putnike do
letovališta. Voditi računa o tome da na put mogu krenuti isključivo
ispravni autobusi.

Napisati funkciju koja ispisuje informaciju o maksimalnoj mogućoj
zaradi svih autobusa zaokruženu na dve decimale. Za izračunavanje
koristiti formulu: ``max_zarada = cena_karte * broj_mesta``.

U izlaznu datoteku ``obracun.txt`` ispisati sve informacije o učitanim
ispravnim autobusima (vrednost polja ``cena_karte`` zaokružiti na dve
decimale), podatak o tome da li autobusi traženog prevoznika mogu da
prevezu sve prijavljene putnike do letovališta, kao i informaciju o
maksimalnoj mogućoj zaradi svih autobusa.

Primer poziva programa::

    ./zad Lasta autobusi.txt 138 obracun.txt 

sa zadatim ulazom u datoteci ``autobusi.txt``:

.. literalinclude:: autobusi.txt

Očekivani izlaz u izlaznoj datoteci ``obracun.txt`` je sledeći:

.. literalinclude:: obracun.txt

U slučaju da traženi prevoznik ne može da preveze sve prijavljene
putnike očekivani izlaz je sledeći:

.. literalinclude:: obracun_ne.txt