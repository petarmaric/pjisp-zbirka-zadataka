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

sa zadatim ulazom u datoteci ``suplementi.txt``:

.. literalinclude:: suplementi.txt

i očekivanim izlazom u datoteci ``cene.txt``:

.. literalinclude:: cene.txt
