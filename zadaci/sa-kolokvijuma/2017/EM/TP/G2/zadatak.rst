Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde struktura
``namirnica_st`` sadrži sledeća polja:

- naziv namirnice (jedna reč, do 13 karaktera)
- količina vitamina C u namirnici (mg/100g)
- vrsta namirnice (jedna reč, do 10 karaktera)

Naravno, struktura ``namirnica_st`` sadrži i polja potrebna za pravilno
formiranje binarnog stabla.

Binarno stablo urediti po ključu "količina vitamina C", u opadajućem redosledu.
Potom iz formiranog binarnog stabla upisati podatke u zadatu izlaznu datoteku,
u sledećem rasporedu polja strukture ``namirnica_st``:

- količina vitamina (koristiti ``"%3u"`` format specifikator)
- naziv namirnice (koristiti ``"%-13s"`` format specifikator)
- vrsta namirnice

i potom u istu izlaznu datoteku upisati informaciju o namirnici sa najviše
vitamina C.

Primer poziva programa::

    ./analiza namirnice.txt izvestaj.txt

sa zadatim ulazom u datoteci ``namirnice.txt``::

    Ananas          9 voce
    Bakalar        26 meso
    BeliLuk        31 povrce
    Brokoli        90 povrce
    CrvenaPaprika 190 povrce
    Grejpfrut      29 voce
    Jagoda         60 voce
    Kivi           89 voce
    Krompir        20 povrce
    Limun          40 voce
    Paradajz       10 povrce
    PilecaJetra    13 meso
    Pomorandza     50 voce
    Ribizla       200 voce
    Sipurak       426 voce
    Spanac         30 povrce
    TelecaJetra    36 meso

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    426 Sipurak       voce
    200 Ribizla       voce
    190 CrvenaPaprika povrce
     90 Brokoli       povrce
     89 Kivi          voce
     60 Jagoda        voce
     50 Pomorandza    voce
     40 Limun         voce
     36 TelecaJetra   meso
     31 BeliLuk       povrce
     30 Spanac        povrce
     29 Grejpfrut     voce
     26 Bakalar       meso
     20 Krompir       povrce
     13 PilecaJetra   meso
     10 Paradajz      povrce
      9 Ananas        voce

    Namirnica sa najvise vitamina C je:
    426 Sipurak       voce

Primer poziva programa kada su ulazni podaci već sortirani u rastućem redosledu::

    ./analiza sorted-asc.txt izvestaj-asc.txt

sa zadatim ulazom u datoteci ``sorted-asc.txt``::

    Limun          40 voce
    Pomorandza     50 voce
    Jagoda         60 voce
    Kivi           89 voce
    Brokoli        90 povrce

i očekivanim izlazom u datoteci ``izvestaj-asc.txt``::

     90 Brokoli       povrce
     89 Kivi          voce
     60 Jagoda        voce
     50 Pomorandza    voce
     40 Limun         voce

    Namirnica sa najvise vitamina C je:
     90 Brokoli       povrce

Primer poziva programa kada su ulazni podaci već sortirani u opadajućem redosledu::

    ./analiza sorted-desc.txt izvestaj-desc.txt

sa zadatim ulazom u datoteci ``sorted-desc.txt``::

    Bakalar        26 meso
    Krompir        20 povrce
    PilecaJetra    13 meso
    Paradajz       10 povrce
    Ananas          9 voce

i očekivanim izlazom u datoteci ``izvestaj-desc.txt``::

     26 Bakalar       meso
     20 Krompir       povrce
     13 PilecaJetra   meso
     10 Paradajz      povrce
      9 Ananas        voce

    Namirnica sa najvise vitamina C je:
     26 Bakalar       meso
