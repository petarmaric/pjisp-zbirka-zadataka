Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``artikal_st`` sastoji od sledećih polja:

- cena (pozitivan realan broj)
- broj prodatih artikala (prirodan broj)
- trgovačka marža u procentima (pozitivan realan broj)
- naziv (jedna reč, do 20 karaktera)

Formirati novi statički niz struktura i upisati ga u zadatu izlaznu datoteku,
pri čemu se struktura ``zarada_st`` sastoji od sledećih polja:

- ostvarena zarada (zaokružena na 2 decimale, koristiti ``"%7.2f"`` format specifikator)
- naziv (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``artikal_st``)

Primer poziva::

    ./hipermarket artikli.txt zarada.txt

sa zadatim ulazom u datoteci ``artikli.txt``::

      40.00  20  5.0 Politika
      50.00 800 10.5 Hleb
    2219.99   2 30.0 Parmezan
     118.36  76 12.3 Mleko

i očekivanim izlazom u datoteci ``zarada.txt``::

      40.00 Politika
    4200.00 Hleb
    1331.99 Parmezan
    1106.43 Mleko
