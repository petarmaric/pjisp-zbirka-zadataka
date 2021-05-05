**Životinjsko carstvo (nije čokoladica :D)**

Iz zadate ulazne datoteke ``zivotinje.txt`` učitati podatke u jednostruko
spregnutu listu, gde struktura ``zivotinja_st`` sadrži sledeća polja:

-  *naziv (*\ jedna reč, maksimalno 8 karaktera\ *),*

-  *prosecna_starost* (pozitivan ceo broj),

-  *broj_jedinki* (realan broj) i

-  *zasticena* (jedna reč, maksimalno 11 karaktera).

Struktura ``zivotinja_st``, takođe sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste. Jednostruko spregnutu listu
formirati dodavanjem novih elemenata na kraj. Voditi računa o tome da je
prilikom kreiranja jednostruko spregnute liste potrebno popuniti polje
``zasticena`` vrednošću “zasticena” ako je broj jedinki manji od 300,
odnosno “nezasticena” ako je broj jedinki veći ili jednak 300.

Pronaći i ispisati sve informacije o trenutno najugroženijoj
životinjskoj vrsti (najugroženijom smatra se životinja sa najmanjim
brojem jedinki).

Primer poziva programa::

    ./a.out zivotinje.txt

sa zadatim ulazom u datoteci ``zivotinje.txt``::

    50.5 Kornjaca 214
    70 krokodil 324
    10 Zmija 126
    70 orao 548
    12 Pas 358
    15 macka 578
    12 zaba 412
    21.5 Kengur 345
    15 koala 125
    112 Meduza 245
    21.5 panda 68
    45 Oktopod 269

i očekivanim ispisom na standardnom izlazu::

    Kornjaca 50.5 214 zasticena
    krokodil 70.0 324 nezasticena
    Zmija 10.0 126 zasticena
    orao 70.0 548 nezasticena
    Pas 12.0 358 nezasticena
    macka 15.0 578 nezasticena
    zaba 12.0 412 nezasticena
    Kengur 21.5 345 nezasticena
    koala 15.0 125 zasticena
    Meduza 112.0 245 zasticena
    panda 21.5 68 zasticena
    Oktopod 45.0 269 zasticena

    Trenutno najugrozenija zivotinja je:
    panda 21.5 68 zasticena