Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``skijaliste_st`` sastoji od sledećih polja:

- naziv skijališta (jedna reč, do 20 karaktera)
- cena dnevne karte u evrima (realan broj)

Sa standardnog ulaza učitati broj dana koje skijaš zeli da bude na skijalištu,
a na standardni izlaz ispisati naziv najjeftinijeg skijališta i cenu koju skijaš
treba da plati (zaokruženu na 2 decimale) za uneti broj dana.

Primer poziva::

    ./a.out skijalista.txt

sa zadatim ulazom u datoteci ``skijalista.txt``::

    Kopaonik 28
    Jahorina 19.9
    StaraPlanina 22.5
    Zlatibor 21

i uniteim brojem dana::

    4

Očekivani ispis na standardnom izlazu::

    Jahorina 79.60