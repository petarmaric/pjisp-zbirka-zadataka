Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``obrok_st`` sadrži sledeća polja:

- naziv obroka (jedna reč, do 20 karaktera)
- vrsta obroka (jedna reč, do 20 karaktera)
- gramaža po obroku
- broj kalorija na 100g

Naravno, struktura ``obrok_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Na osnovu zadate vrste obroka ``vrsta`` iz formirane liste
ispisati na standardni izlaz sve obroke koji pripadaju toj vrsti
u sledećem rasporedu polja strukture ``obrok_st``:

- naziv obroka
- gramaža po obroku
- broj kalorija na 100g

i potom ispisati informaciju o obroku izabrane vrste koji ima najmanje kalorija
(broj kalorija po obroku se računa kao proizvod gramaže i broja kalorija na 100 grama podeljenog sa 100).

Primer poziva programa::

    ./a.out dezert obroci.txt

sa ``vrsta=dezert`` i zadatim ulazom u datoteci ``obroci.txt``::

    sarma glavno_jelo 250 126
    ruska_salata prilog 50 113
    supa predjelo 130 40
    prasetina glavno_jelo 250 345
    baklava dezert 60 420
    krompir_salata prilog 80 82
    bajadera dezert 68 440
    jagnjetina glavno_jelo 250 318
    cokoladna_torta dezert 80 490

i očekivanim ispisom na standardnom izlazu::

    baklava 60 420
    bajadera 68 440
    cokoladna_torta 80 490

    Obrok sa najmanje kalorija je baklava sa ukupno 252 kalorija.