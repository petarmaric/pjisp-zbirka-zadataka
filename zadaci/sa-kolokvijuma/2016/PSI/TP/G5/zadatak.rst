Kabel je predstavljen sledećim karakteristikama:

* Kategorija kabla (jedna reč, do 10 karaktera)
* Tip kabla (jedna reč, izračunati broj potrebnih karaktera) sa sledećim vrednostima:

  * ``UTP`` kabel (bez dodatne izolacije)
  * ``STP`` kabel (sa dodatnom izolacijom)
  * ``UTP/STP`` kabel (obe varijante podržane kod kategorije kabla)

* Brzina prenosa u megabitima po sekundi (neoznačen, ceo broj)
* Maksimalni protok u megahercima (neoznačen, ceo broj)
* Cena po metru (pozitivan, realan broj)

Učitati kablove iz ulazne datoteke i uraditi sledeće:

a. Formirati binarno stablo pretrage u odnosu na kategoriju kabla.
   Ispisati sve kategorije kablova sortirane u rastućem redosledu u izlaznu datoteku ``kablovi.txt`` zajedno sa jedinicama mere (za brzinu prenosa je Mbps, za maksimalni protok je MHz) i realnim vrednostima zaokruženim na dve decimale.
b. Na osnovu zadate kategorije kabla izvršiti pretragu nad stablom. 
   Ukoliko postoji kabel zadate kategorije, izračunati cenu kabla na osnovu zadatog broja metara.
   Kategorija kabla i dužina u metrima zadaju se kao argumenti komandne linije. 
   Dobijeni rezultat ispisati datoteku koja nosi naziv ``<ime_kabla>_cena.txt`` zaokruženu na dve decimale. 
   U izlaznu datoteku ``odgovarajuci_kablovi.txt`` ispisati sve kablove koji imaju veću ili jednaku kako brzinu prenosa tako i maksimalni protok.
   Ukoliko ne postoji traženi tip kabla, ne formirati izlazne datoteke! 
c. Ispisati sve kablove koji mogu biti zadatog tipa u izlaznu datoteku ``<tip_kabla>.txt``.
   Tip kabla se zadaje kao argument komandne linije.

Format poziva programa::

     <ime_programa> <ime_ulazne_datoteke> <kategorija> <dužina> <tip>

Primer poziva programa::

    ./a.out ponuda.txt Cat5e 5 UTP

Primer ulazne datoteke ``ponuda.txt``::

    Cat3 UTP 10 16 0.5
    Cat5e UTP 1000 100 1.2
    Cat6 UTP/STP 1000 250 1.5
    Cat5 UTP 100 100 1
    Cat7 STP 10000 600 2.5
    Cat6a STP 10000 500 2

Primer očekivanog izlaza ``kablovi.txt``::

    Cat3 UTP 10 Mbps 16 MHz 0.50
    Cat5 UTP 100 Mbps 100 MHz 1.00
    Cat5e UTP 1000 Mbps 100 MHz 1.20
    Cat6 UTP/STP 1000 Mbps 250 MHz 1.50
    Cat6a STP 10000 Mbps 500 MHz 2.00
    Cat7 STP 10000 Mbps 600 MHz 2.50

Primer očekivanog izlaza ``Cat5e_cena.txt``::

    6.00

Primer očekivanog izlaza ``odgovarajuci_kablovi.txt``::

    Cat5e UTP 1000 Mbps 100 MHz 1.20
    Cat6 UTP/STP 1000 Mbps 250 MHz 1.50
    Cat6a STP 10000 Mbps 500 MHz 2.00
    Cat7 STP 10000 Mbps 600 MHz 2.50

Primer očekivanog izlaza ``UTP.txt``::

    Cat3 UTP 10 Mbps 16 MHz 0.50
    Cat5 UTP 100 Mbps 100 MHz 1.00
    Cat5e UTP 1000 Mbps 100 MHz 1.20
    Cat6 UTP/STP 1000 Mbps 250 MHz 1.50

