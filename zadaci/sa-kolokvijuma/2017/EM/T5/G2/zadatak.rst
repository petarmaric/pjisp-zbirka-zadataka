Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``restoran_st`` sadrži sledeća polja:

- naziv restorana (jedna reč, do 10 karaktera)
- vrsta kuhinje (jedna reč, do 20 karaktera)
- prosečna ocena korisnika (pozitivan realan broj)

Naravno, struktura ``restoran_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Na osnovu zadate vrste kuhinje ``vrsta`` iz formirane liste upisati podatke u
zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``restoran_st``:

- prosečna ocena korisnika (zaokružena na 1 decimalu, koristiti ``"%3.1f"`` format specifikator)
- naziv restorana (koristiti ``"%-10s"`` format specifikator)
- vrsta kuhinje

i potom u istu izlaznu datoteku upisati informaciju o najbolje ocenjenom
restoranu koji služi hranu zadate ``vrste`` kuhinje.

Primer poziva::

    ./restorani italijanski novi-sad.txt izvestaj.txt

sa ``vrsta=italijanski`` i zadatim ulazom u datoteci ``novi-sad.txt``::

    Cremansa   italijanski  4.3
    Sekunda    italijanski  3.9
    Inimigos   americki     4.5
    LaCattura  italijanski  4.7
    FutureFood americki     4.4
    Eva        srpski       4.8
    Kokoda     srpski       4.3

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    4.3 Cremansa   italijanski
    3.9 Sekunda    italijanski
    4.5 Inimigos   americki
    4.7 LaCattura  italijanski
    4.4 FutureFood americki
    4.8 Eva        srpski
    4.3 Kokoda     srpski

    Najbolje ocenjen italijanski restoran u gradu je:
    4.7 LaCattura  italijanski

Primer poziva kada restoran sa zadatim kriterijumima ne postoji::

    ./restorani kineski kraljevo.txt izvestaj.txt

sa ``vrsta=kineski`` i zadatim ulazom u datoteci ``kraljevo.txt``::

    PizzaSlow  italijanski  4.5
    SaleDjodjo italijanski  4.4

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    4.5 PizzaSlow  italijanski
    4.4 SaleDjodjo italijanski

    U gradu ne postoji kineski restoran!
