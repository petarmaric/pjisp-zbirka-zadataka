Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``paket_st`` sastoji od sledećih polja:

- naziv zemlje (jedna reč, do 20 karaktera)
- naziv operatera (jedna reč, do 20 karaktera)
- mesečna pretplata (prirodan broj)
- broj KWh uključenih u pretplatu (prirodan broj)
- cena po KWh nakon potrošenih besplatnih KWh (pozitivan realan broj)

Na osnovu zadatog mesečnog broja KWh ``potroseno_kwh`` (prirodan broj)
formirati novi statički niz struktura i upisati ga u zadatu izlaznu datoteku,
pri čemu se struktura ``cena_st`` sastoji od sledećih polja:

- ukupna cena (zaokružena na 2 decimale, koristiti ``"%7.2f"`` format specifikator)
- naziv zemlje (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``paket_st``)
- naziv operatera (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``paket_st``)

Primer poziva::

    ./potrosnja 90 paketi.txt cene.txt

sa ``potroseno_kwh=90`` i zadatim ulazom u datoteci ``paketi.txt``::

    Srbija     EPS             500  50  3.92
    Srbija     TajkunDOO       100   2  9.56
    Madjarska  HuElectro       495 100 12.31
    Slovenija  Elektroprivreda  50   0 15.99
    Slovenija  AlpEnergy         0   0 16.99

i očekivanim izlazom u datoteci ``cene.txt``::

     656.80 Srbija EPS
     941.28 Srbija TajkunDOO
     495.00 Madjarska HuElectro
    1489.10 Slovenija Elektroprivreda
    1529.10 Slovenija AlpEnergy
