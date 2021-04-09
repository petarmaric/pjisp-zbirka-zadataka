Iz zadate ulazne datoteke ``posiljke.txt`` učitati statički niz
struktura, pri čemu se struktura ``posiljka_st`` sastoji od sledećih
polja:

-  ``sifra`` (jedna reč, maksimalno 5 karaktera),
-  ``zemlja`` (jedna reč, maksimalno 10 karaktera),
-  ``vrednost`` (jedna reč, maksimalno 4 karaktera) – izražena u evrima,
-  ``tezina`` (realan broj) – izražena u gramima i
-  ``cena`` (realan broj).

Na osnovu parametra ``odabrana_zemlja`` koji se prihvata preko standardnog
ulaza, izračunati cenu pošiljke nakon carine na sledeći način:

-  ako je vrednost pošiljke veća od 100 evra, težina veća od 1000 grama
      i zemlja odgovara vrednosti unetog parametra *odabrana_zemlja*
      tada visina cene odgovara visini vrednosti pošiljke uvećane za 18%
-  u suprotnom, visina cene odgovara visini vrednosti pošiljke.

Preko standardnog ulaza korisnik treba da unese i parametar
*vrsta_ispisa* čije su moguće vrednosti -1 ili 1 (obavezno realizovati
proveru validnosti unete vrednosti parametra). Vrednost parametra -1
označava da je ispis informacija o svim pošiljkama nakon carine potrebno
realizovati preko standardnog izlaza, dok se u slučaju vrednosti 1
podaci o pošiljkama ispisuju u izlaznu datoteku ``carinjenje.txt``.
Prilikom ispisa podatke o svim pošiljkama neophodno je sortirati u
opadajućem redosledu *zemlje* (pomoć: koristiti funkcije za rad sa
stringovima).

Primer poziva programa:

.. code:: bash

  ./zad posiljke.txt carinjenje.txt

sa zadatim ulazom u datoteci ``posiljke.txt``:

.. literalinclude:: posiljke.txt

Očekivani izlaz u izlaznoj datoteci ``carinjenje.txt`` ukoliko je
vrednost parametra *odabrana_zemlja* unetog preko standardnog ulaza
„\ *Slovenija*\ “ je sledeći:

.. literalinclude:: carinjenje-slovenija.txt

Očekivani izlaz u izlaznoj datoteci ``carinjenje.txt`` ukoliko je vrednost
parametra *odabrana_zemlja* unetog preko standardnog ulaza
„\ *Holandija*\ “ je sledeći:

.. literalinclude:: carinjenje-holandija.txt

U slučaju da je vrednost parametra *vrsta_ispisa* unetog preko
standardnog ulaza „\ *1*\ “, ispis će se vršiti u izlaznoj datoteci
``carinjenje.txt`` (ako parametar ima vrednost *-1* ispis ostaje
nepromenjen, ali se realizuje na standardnom izlazu).

Prilikom unosa parametara koji se zadaju preko standardnog ulaza, format
treba da bude sledeći:

.. code:: bash

  Uneti naziv zemlje: Holandija 
  Uneti broj (-1 - ispis na standardni izlaz / 1 - ispis u datoteku): 1

