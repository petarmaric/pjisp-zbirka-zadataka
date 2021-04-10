Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``igrica_st`` sadrži sledeća polja:

- naziv igre (jedna reč, do 20 karaktera)
- pozicija na rang listi (pozitivan ceo broj)
- da li je igra podržana na Windows operativnom sistemu (tačno jedaj karakter, + ako jeste, - ako nije)
- da li je igra podržana na MacOS operativnom sistemu (tačno jedaj karakter, + ako jeste, - ako nije)
- da li je igra podržana na Linux operativnom sistemu (tačno jedaj karakter, + ako jeste, - ako nije)

Naravno, struktura ``igrica_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Igre ispisati na standardni izlaz sortirane po poziciji na rang listi (sortirati prilikom učitavanja u listu) u sledećem formatu:

- pozicija na rang listi
- naziv igre

i potom ispisati na kojim operativnim sistemima je podržana najbolje rangirana igra.

Primer poziva programa::

    ./a.out igre.txt

sa zadatim ulazom u datoteci ``igre.txt``::

    Phasmophobia 4 + - -
    Rust 1 + + -
    Hades 7 + + -
    Cyberpunk2077 3 + - -
    AmongUs 8 + - -
    Raft 5 + - -
    SeaOfThieves 6 + - -
    Counter-Strike 2 + + +

i očekivanim ispisom na standardnom izlazu ::

    1 Rust
    2 Counter-Strike
    3 Cyberpunk2077
    4 Phasmophobia
    5 Raft
    6 SeaOfThieves
    7 Hades
    8 AmongUs

    Najbolje rangirana igra je Rust i podrzana je na sledecim operativnim sistemima:
    Windows
    MacOS