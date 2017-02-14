Podaci o kretanjima učesnika u lavirintu predstavljeni su preko sledećih polja:

* Redni broj takmičara (neoznačen, ceo broj)
* Ime (jedna reč, do 20 karaktera)
* Prezime (jedna reč, do 20 karaktera)
* Stanje (jedna reč, odrediti dužinu stringa tako da može da stane najduža reč) koje može biti:

  * ``STEP`` – učesnik je zakoračio napred
  * ``CROSS`` – učesnik se nalazi na raskršću između više puteva
  * ``STOP`` – učesnik je naišao na ćorsokak

U ulaznoj datoteci nalaze se podaci o stanjima takmičara dok su se kretali kroz lavirint. Podatke iz ulazne datoteke obraditi na sledeći način:

a) Učitati korake svakog takmičara u poseban stek na sledeći način: vršiti operaciju ``push`` na stek dokle god je stanje ``STEP`` ili ``CROSS``. 
   U slučaju stanja ``STOP``, vratiti se pomoću operacije ``pop`` do poslednjeg ``CROSS`` stanja, zatim nastaviti sa učitavanjem iz datoteke.
b) Obrnuti sadržaj svakog steka tako što će se stari stek prazniti dok se novi puni kako bi se dobile putanje od početka do kraja za svakog učesnika.
c) Ispisati korake svakog takmičara u zasebnu izlaznu datoteku čiji naziv ima sledeći format: ``"<redni_broj>_<ime>_<prezime>.txt"``. 
   Prebrojati broj koraka i odrediti takmičare čija putanja od ulaza do izlaza ima manje od zadatog broja koraka. 
   Ispisati imena i prezimena tih takmičara na standardni izlaz.

Fizička realizacija steka je proizvoljna: sekvencijalna ili spregnuta.

Program treba pokretati u sledećem formatu::

    <ime_programa> <ulazna_datoteka> <broj_ucesnika> <broj_koraka> 

Primer poziva programa:: 

    ./a.out log.txt 3 7

Primer ulazne datoteke ``log.txt``::

    1 Tod Snavely      STEP
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers STEP
    1 Tod Snavely      STEP
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers STEP
    1 Tod Snavely      CROSS
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers CROSS
    1 Tod Snavely      STEP
    2 Eloisa Taormina  CROSS
    3 Heriberto Bowers STEP
    1 Tod Snavely      STEP
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers STOP
    1 Tod Snavely      STOP
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers STEP
    1 Tod Snavely      STEP
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers STEP
    1 Tod Snavely      STEP
    2 Eloisa Taormina  STOP
    3 Heriberto Bowers CROSS
    1 Tod Snavely      STEP
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers STEP
    2 Eloisa Taormina  STEP
    3 Heriberto Bowers STEP
    3 Heriberto Bowers STOP
    3 Heriberto Bowers STEP
    3 Heriberto Bowers STEP
    3 Heriberto Bowers STEP

Očekivani sadržaj izlazne datoteke ``1_Tod_Snavely.txt``::
    
    1 Tod Snavely STEP
    1 Tod Snavely STEP
    1 Tod Snavely CROSS
    1 Tod Snavely STEP
    1 Tod Snavely STEP
    1 Tod Snavely STEP
    ------------------------------
    6

Očekivani sadržaj izlazne datoteke ``2_Eloisa_Taormina.txt``::

    2 Eloisa Taormina STEP
    2 Eloisa Taormina STEP
    2 Eloisa Taormina STEP
    2 Eloisa Taormina CROSS
    2 Eloisa Taormina STEP
    2 Eloisa Taormina STEP
    ------------------------------
    6

Očekivani sadržaj izlazne datoteke ``3_Heriberto_Bowers.txt``::

    3 Heriberto Bowers STEP
    3 Heriberto Bowers STEP
    3 Heriberto Bowers CROSS
    3 Heriberto Bowers STEP
    3 Heriberto Bowers STEP
    3 Heriberto Bowers CROSS
    3 Heriberto Bowers STEP
    3 Heriberto Bowers STEP
    3 Heriberto Bowers STEP
    ------------------------------
    9

Očekivani ispis na ``standardnom izlazu``::

    Tod Snavely
    Eloisa Taormina 

