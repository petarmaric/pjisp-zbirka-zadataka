Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde struktura
``restoran_st`` sadrži sledeća polja:

- naziv restorana (jedna reč, do 10 karaktera)
- vrsta kuhinje (jedna reč, do 20 karaktera)
- prosečna ocena korisnika (pozitivan realan broj)

Naravno, struktura ``restoran_st`` sadrži i polja potrebna za pravilno
formiranje binarnog stabla.

Binarno stablo urediti po ključu "prosečna ocena korisnika", u opadajućem
redosledu. Potom iz formiranog binarnog stabla upisati podatke u zadatu izlaznu
datoteku, u sledećem rasporedu polja strukture ``restoran_st``:

- prosečna ocena korisnika (zaokružena na 1 decimalu, koristiti ``"%3.1f"`` format specifikator)
- naziv restorana (koristiti ``"%-10s"`` format specifikator)
- vrsta kuhinje

i potom u istu izlaznu datoteku upisati informaciju o najgore ocenjenom
restoranu.

Primer poziva programa::

    ./restorani novi-sad.txt izvestaj.txt

sa zadatim ulazom u datoteci ``novi-sad.txt``::

    Cremansa   italijanski  4.3
    Sekunda    italijanski  3.9
    Inimigos   americki     4.5
    LaCattura  italijanski  4.7
    FutureFood americki     4.4
    Eva        srpski       4.8
    Kokoda     srpski       4.2

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    4.8 Eva        srpski
    4.7 LaCattura  italijanski
    4.5 Inimigos   americki
    4.4 FutureFood americki
    4.3 Cremansa   italijanski
    4.2 Kokoda     srpski
    3.9 Sekunda    italijanski

    Najgore ocenjen restoran u gradu je:
    3.9 Sekunda    italijanski

Primer poziva programa::

    ./restorani kineski kraljevo.txt izvestaj.txt

sa zadatim ulazom u datoteci ``kraljevo.txt``::

    SaleDjodjo italijanski  4.4
    PizzaSlow  italijanski  4.5

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    4.5 PizzaSlow  italijanski
    4.4 SaleDjodjo italijanski

    Najgore ocenjen restoran u gradu je:
    4.4 SaleDjodjo italijanski
