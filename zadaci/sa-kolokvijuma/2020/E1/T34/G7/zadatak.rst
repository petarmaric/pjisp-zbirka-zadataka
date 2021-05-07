

Iz zadate ulazne datoteke ``sefovi.txt`` učitati statički niz
struktura, pri čemu se struktura ``sef_st`` sastoji od sledećih polja:

- sifra (jedna reč, maksimalno 5 karaktera),
- zauzetost (jedna reč, maksimalno 8 karaktera),
- cena_zakupa (prirodan broj) i
- tezina_robe (realan broj) – izražena u gramima.

Na osnovu parametra ``max_tezina`` koji se prihvata preko standardnog
ulaza (izražena u gramima), izračunati cenu zakupa sefa nakon
obračunavanja dodatnog poreza (procesu izračunavanja dodatnog poreza
podležu isključivo zauzeti sefovi; cena zakupa slobodnih sefova ostaje
nepromenjena) na sledeći način:

- ako je težina robe smeštene u zauzetom sefu veća od vrednosti unetog parametra ``max_tezina``, cena zakupa odgovarajućeg zauzetog sefa uvećava se za 15%
- u suprotnom, cena zakupa odgovarajućeg zauzetog sefa ostaje nepromenjena.

Potrebno je napisati funkciju koja vraća informaciju o ukupnom broju
trenutno slobodnih sefova.

Ispis informacija o svim sefovima nakon obračuna dodatnog poreza i o
ukupnom broju trenutno slobodnih sefova potrebno je realizovati u
izlaznu datoteku ``oporezovani.txt``. Prilikom ispisivanja realne
brojeve zaokružiti na jednu decimalu.

Primer poziva programa::

    ./zad sefovi.txt 300.0 oporezovani.txt

sa zadatim ulazom u datoteci ``sefovi.txt``:

.. literalinclude:: sefovi.txt

Očekivani izlaz u izlaznoj datoteci ``oporezovani.txt`` je sledeći:

.. literalinclude:: oporezovani.txt