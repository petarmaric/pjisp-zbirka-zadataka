Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``serija_st`` sastoji od sledećih polja:

- naziv (jedna reč, do 30 karaktera)
- IMDB ocena (pozitivan realan broj)
- maksimalna zabeležena gledanost (pozitivan realan broj)
- maksimalan broj meseci između dve sezone (prirodan broj)

Formirati novi statički niz struktura i upisati ga u zadatu izlaznu datoteku,
pri čemu se struktura ``hype_st`` sastoji od sledećih polja:

- hype faktor (zaokružen na 2 decimale, koristiti ``"%6.2f"`` format specifikator)
- naziv (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``serija_st``)

Korisne matematičke formule::

    hype_faktor = imdb_ocena * max_vreme_izmedju_sezona / max_gledanost

Primer poziva::

    ./hype_train serije.txt hype.txt

sa zadatim ulazom u datoteci ``serije.txt``::

    SlickAndSmorty        9.3   2.86  18
    EastWorld             8.8   2.24  16
    GameOfPhones          9.5  12.07  20
    VentureSisters        8.5   1.53  31
    EvangerionNoYakusoku  8.0   2.16  59

i očekivanim izlazom u datoteci ``hype.txt``::

     58.53 SlickAndSmorty
     62.86 EastWorld
     15.74 GameOfPhones
    172.22 VentureSisters
    218.52 EvangerionNoYakusoku
