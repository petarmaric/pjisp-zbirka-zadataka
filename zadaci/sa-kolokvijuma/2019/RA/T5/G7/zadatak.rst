Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``ukras_st`` sadrži sledeća polja:

- naziv prodavnice (jedna reč, do 30 karaktera)
- naziv ukrasa (jedna reč, do 30 karaktera)
- vrsta ukrasa (jedna reč, do 30 karaktera)
- cena ukrasa (pozitivan realan broj)

Vrsta ukrasa može biti: lampice, lampioni i jelka

Naravno, struktura ``ukras_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

U izlaznu datoteku ispisati ukrase koje treba kupiti, tako da se što manje novca potroši na kupovinu ukrasa, a da korisnik ima po jedan ukras od svake vrste ukrasa.

Podatke ispisati u sledećem rasporedu polja strukture ``ukras_st``:

- cena ukrasa
- naziv ukrasa
- naziv prodavnice

i potom u istu izlaznu datoteku upisati ukupnu količinu novca koja treba da se potroši na ukrase da bi korisnik imao po jedan ukras od svake vrske ukrasa.

Sve realne vrednosti zaokružiti na 2 decimale pri ispisu.
U izlaznu datoteku ukrase ispisati u opadajućem redosledu cena.

Primer poziva programa::

    ./a.out ukrasi.txt spisak_za_kupovinu.txt

sa zadatim ulazom u datoteci ``ukrasi.txt``::


    Kineska_prodavnica 6_lampiona_sa_sljokicama lampioni 559.99
    Drvosece_doo prirodna_jelka jelka 4000
    House_centar sarene_lampice lampice 400
    Linda 6_velikih_lampiona lampioni 420
    Linda bele_lampice lampice 220.20
    House_centar 18_malih_lampiona lampioni 390
    Linda bela_plasticna_jelka jelka 1399.90
    Kineska_prodavnica crvene_lampice lampice 228.77
    House_centar zelena_plasticna_jelka jelka 1200


i očekivanim izlazom u datoteci ``spisak_za_kupovinu.txt``::

    1200.00 zelena_plasticna_jelka House_centar
    390.00 18_malih_lampiona House_centar
    220.20 bele_lampice Linda

    Ukupna cena je: 1810.20

Ako u ulaznoj datoteci ne postoji ni jedan ukras neke vrste, potrebno je izostaviti tu vrstu ukrasa pri ispisu u izlaznu datoteku.