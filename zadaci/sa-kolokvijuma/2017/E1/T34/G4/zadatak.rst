Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``zelja_st`` sastoji od sledećih polja:

- broj gostiju (prirodan broj)
- naziv željene pizze (jedna reč, do 20 karaktera)

Na osnovu prosečnog apetita gostiju u parčadima pizze ``apetit`` (pozitivan
realan broj) formirati novi statički niz struktura i upisati ga u zadatu
izlaznu datoteku, pri čemu se struktura ``porudzbina_st`` sastoji od sledećih
polja:

- broj potrebnih parčadi (zaokružen na 1 decimalu, koristiti ``"%5.1f"`` format specifikator)
- broj potrebnih *celih* pizza (koristiti ``"%2u"`` format specifikator)
- naziv željene pizze (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``zelja_st``)

Smatrati da se jedna cela pizza seče na 8 jednakih parčadi.

Primer poziva::

    ./zurka 2.5 zelje.txt nabavka.txt

sa ``apetit=2.5`` i zadatim ulazom u datoteci ``zelje.txt``::

    40 Capricciosa
    27 Madjarica
    11 Margharita
     3 Vegetale
    16 Prosciutto

i očekivanim izlazom u datoteci ``nabavka.txt``::

    100.0 13 Capricciosa
     67.5  9 Madjarica
     27.5  4 Margharita
      7.5  1 Vegetale
     40.0  5 Prosciutto
