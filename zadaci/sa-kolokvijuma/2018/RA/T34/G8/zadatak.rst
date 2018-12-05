Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``takmicar_st`` sastoji od sledećih polja:

- ime (jedna reč, do 16 karaktera)
- prezime (jedna reč, do 16 karaktera)
- ocena prvog člana stručnog žirija (prirodan broj)
- ocena drugog člana stručnog žirija (prirodan broj)
- ocena trećeg člana stručnog žirija (prirodan broj)

Formirati novi statički niz struktura i upisati ga u zadatu izlaznu datoteku,
pri čemu se struktura ``ocena_st`` sastoji od sledećih polja:

- prosečna ocena stručnog žirija (zaokružena na 2 decimale, koristiti ``"%4.2f"`` format specifikator)
- ime (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``takmicar_st``)
- prezime (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``takmicar_st``)

Primer poziva::

    ./hotshot takmicari.txt ocene.txt

sa zadatim ulazom u datoteci ``takmicari.txt``::

    Bingham  Madsen  5  5  5
    Abi      Khan    5  2  1
    Glee     Hayes   1  0  0

i očekivanim izlazom u datoteci ``ocene.txt``::

    5.00 Bingham Madsen
    2.67 Abi Khan
    0.33 Glee Hayes
