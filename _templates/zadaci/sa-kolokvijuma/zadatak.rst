.. warning::

   Ovo je samo primer teksta zadatka, ne zaboravite da izmenite:

   - ``{{ zadatak_dir }}/zadatak.rst``
   - ``{{ zadatak_dir }}/resenje.c``





Iz zadate ulazne datoteka učitati statički niz struktura,
pri čemu se struktura ``pacijent_st`` sastoji od sledećih polja:

- Ime (jedna reč, do 20 karaktera)
- Prezime (jedna reč, do 20 karaktera)
- Holesterol (realan broj)
- Krvni pritisak (prirodan broj)
- Šećer u krvi (realan broj)

Na osnovu zadatog tipa analize ``tip_analize`` (``holesterol``, ``pritisak`` ili ``secer``) i sledećih pravila:

===========  =================
Tip analize  Prihvatljiv opseg
===========  =================
holesterol   holesterol < 5.2
pritisak     90 ≤ pritisak < 120
secer        3.9 ≤ secer < 5.6
===========  =================

formirati novi statički niz struktura i upisati ga u zadatu izlaznu datoteku,
pri čemu se struktura ``analiza_st`` sastoji od sledećih polja:

- Upozorenje (1 znak):

  - '+' ako je vrednost van prihvatljivog opsega
  - '-' ako je vrednost u okviru prihvatljivog opsega

- Ime (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``pacijent_st``)
- Prezime (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``pacijent_st``)

Primer poziva::

    ./proveri pritisak pacijenti.txt izvestaj.txt

sa ``tip_analize=pritisak``, zadatim ulazom u datoteci ``pacijenti.txt``::

    Homer  Simpson 13.5 178 7.8
    Skinny Pete     4.3  85 3.6
    Johnny Bravo    4.8  90 5.4
    Pizza  Lover    5.2 120 3.9

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    + Homer Simpson
    + Skinny Pete
    - Johnny Bravo
    + Pizza Lover
