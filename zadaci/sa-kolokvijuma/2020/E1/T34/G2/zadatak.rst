Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``suplement_st`` sastoji od sledećih polja:

- naziv suplementa (jedna reč, do 20 karaktera)
- broj tableta u pakovanju (pozitivan ceo broj)
- broj tableta koje se piju svakog dana (pozitivan ceo broj)
- cena po pakovanju (pozitivan realan broj)

Na osnovu zadatih podataka formirati novi
statički niz struktura i upisati ga u zadatu izlaznu datoteku, pri čemu se
struktura ``cena_st`` sastoji od sledećih polja:

- cena suplementa po danu ako se uzima preporučen broj tableta (zaokružena na 2 decimale, koristiti ``"%.2f"`` format specifikator)
- naziv suplementa (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``suplement_st``)

Primer poziva::

    ./suplementi suplementi.txt cene.txt

sa zadatim ulazom u datoteci ``suplementi.txt``::

    vitamin_c 40 2 344.99
    cink 30 1 128.00
    vitamin_d 60 3 899.99
    B12 44 3 755.55
    magnezijum 20 1 455.66

i očekivanim izlazom u datoteci ``cene.txt``::

    17.25 vitamin_c
    4.27 cink
    45.00 vitamin_d
    51.51 B12
    22.78 magnezijum
