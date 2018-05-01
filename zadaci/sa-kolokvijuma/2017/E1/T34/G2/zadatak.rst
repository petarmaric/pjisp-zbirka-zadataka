Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``gorivo_st`` sastoji od sledećih polja:

- skraćena oznaka grada (jedna reč, tačno 2 karaktera)
- tip goriva (jedna reč, do 10 karaktera)
- cena goriva (pozitivan realan broj)

Na osnovu fiksnog iznosa povećanja akcize na sva goriva ``akciza`` (pozitivan
realan broj) formirati novi statički niz struktura i upisati ga u zadatu
izlaznu datoteku, pri čemu se struktura ``analiza_st`` sastoji od sledećih
polja:

- nova cena goriva (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator)
- procenat uvećanja cene goriva (zaokružen na 2 decimale, koristiti "%5.2f" format specifikator)
- skraćena oznaka grada (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``gorivo_st``)
- tip goriva (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``gorivo_st``)

Primer poziva::

    ./ekologija 7.32 pre.txt posle.txt

sa ``akciza=7.32`` i zadatim ulazom u datoteci ``pre.txt``::

    NS gas     71.90
    NS benzin 155.20
    NS dizel  165.15
    NI gas     69.30
    NI benzin 155.30
    NI dizel  165.20
    BG gas     70.20
    BG benzin 155.50
    BG dizel  165.40

i očekivanim izlazom u datoteci ``posle.txt``::

     79.22 10.18 NS gas
    162.52  4.72 NS benzin
    172.47  4.43 NS dizel
     76.62 10.56 NI gas
    162.62  4.71 NI benzin
    172.52  4.43 NI dizel
     77.52 10.43 BG gas
    162.82  4.71 BG benzin
    172.72  4.43 BG dizel
