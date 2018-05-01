.. epigraph::
    | Ko leti - vredi,
    | ko vredi - leti,
    | ko ne leti - ne vredi.

    -- Otto Grunf

Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``prevoznik_st`` sastoji od sledećih polja:

- naziv operatera (jedna reč, do 20 karaktera)
- cena karte (pozitivan realan broj)
- maksimalna masa besplatnog prtljaga (pozitivan realan broj)
- doplata za prekomerni prtljag po kilogramu (pozitivan realan broj)

Na osnovu zadate mase prtljaga ``masa`` (pozitivan realan broj) formirati novi
statički niz struktura i upisati ga u zadatu izlaznu datoteku, pri čemu se
struktura ``cena_st`` sastoji od sledećih polja:

- ukupna cena leta (zaokružena na 2 decimale, koristiti ``"%7.2f"`` format specifikator)
- naziv operatera (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``prevoznik_st``)

Primer poziva::

    ./letovi 23.5 avioprevoznici.txt cene.txt

sa ``masa=23.5`` i zadatim ulazom u datoteci ``avioprevoznici.txt``::

    JAT       150.0 2.5 1.5
    Wizz       52.3 0.0 7.0
    Lufthansa 210.0 7.0 2.5
    Delta     180.0 6.5 1.0

i očekivanim izlazom u datoteci ``cene.txt``::

    181.50 JAT
    216.80 Wizz
    251.25 Lufthansa
    197.00 Delta
