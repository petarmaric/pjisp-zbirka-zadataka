Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``lego_st`` sadrži sledeća polja:

- naziv seta (jedna reč, do 20 karaktera)
- kolekcija kojoj set pripada (jedna reč, do 20 karaktera)
- broj kockica u setu (pozitivan ceo broj)

Naravno, struktura ``lego_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Na osnovu zadate kolekcije ``kolekcija`` iz formirane liste upisati podatke koji pripadaju zadatoj kolekciji u
zadatu izlaznu datoteku u opadajućem redosledu na osnovu broja kockica u setu, u sledećem rasporedu polja strukture ``lego_st``:

- broj kockica u setu
- naziv seta

Primer poziva programa::

    ./lego minecraft setovi.txt izvestaj.txt

sa ``kolekcija=minecraft`` i zadatim ulazom u datoteci ``setovi.txt``:

.. literalinclude:: setovi.txt

i očekivanim izlazom u datoteci ``izvestaj.txt``:

.. literalinclude:: izvestaj.txt

sa ``kolekcija=minions`` (nepostojeca kolekcija) i istom ulaznom datotekom, očekivani izlaz u datoteci ``izvestaj.txt`` je:

.. literalinclude:: izvestaj_nema_kolekcije.txt