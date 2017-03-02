Učinak fudbalskog tima tokom sezone opisan je sledećim poljima:

* naziv tima (jedna reč, do 30 karaktera)
* gol razlika (celobrojna vrednost)
* broj bodova (neoznačena, celobrojna vrednost)

Svaki tim, pored imena i gol razlike, u ulaznoj datoteci postoje, redom, broj pobeda, nerešenih utakmica i poraza.
Sa podacima iz ulazne datoteke uraditi sledeće:

a. Učitati ih u niz struktura koje odgovaraju gornjem opisu. 
   Iskoristiti broj pobeda, nerešenih utakmica i poraza za računanje trenutnog broja bodova po sledećem principu:

   * Pobeda nosi 3 boda
   * Nerešena utakmica nosi 1 bod
   * Poraz nosi 0 bodova

b. U izlaznu datoteku ispisati sve timove koji se sa brojem bodova nalaze u intervalu: :math:`[avg_{bodovi}, arg]`, 
   gde su granice, redom, srednja vrednost bodova na tabeli i zadata vrednost argumenta komandne linije.
   Datoteku nazvati sa prefiksom ``između_proseka_i_``, potom vrednost ``arg`` i postfiks ``_bodova.txt``.
c. Sortirati tabelu po broju bodova. U slučaju da dve ekipe imaju isti broj bodova, prednost ima ona ekipa koja ima veću gol razliku. 
   Prve tri ekipe idu u "Ligu šampiona", sledeće dve u "Ligu Evrope", a poslednje tri su u "zoni ispadanja". 
   Prilikom ispisa u izlaznu datoteku posebno podvući crtu ispod timova koji su plasirani za "Lige", odnosno iznad "zone ispadanja".

Primer poziva programa::

    ./a.out statistika.txt tabela.txt 20

Primer sadržaja ulazne datoteke ``statistika.txt``::

    Atalanta 7 8 1 4
    Bologna -5 4 4 5
    Cagliari -10 5 1 7
    Chievoverona -1 5 3 5
    Crotone -16 1 2 10
    Empoli -11 2 4 7
    Fiorentina 7 5 5 2
    Genoa 0 4 4 4
    Inter 2 5 3 5
    Juventus 19 11 0 2
    Lazio 12 7 4 2
    Milan 4 8 2 3
    Napoli 9 7 3 3
    Palermo -16 1 3 9
    Pescara -14 1 4 8
    Roma 16 8 2 3
    Sampdoria -3 5 3 5
    Sassuolo -9 4 1 8
    Torino 13 6 4 3
    Udinese -4 4 3 6

Očekivani sadržaj izlazne datoteke ``izmedju_proseka_i_25_bodova.txt``::

    Atalanta 7 25
    Chievoverona -1 18
    Fiorentina 7 20
    Inter 2 18
    Lazio 12 25
    Napoli 9 24
    Sampdoria -3 18
    Torino 13 22

Očekivani sadržaj izlazne datoteke ``tabela.txt``::

    Juventus 19 33
    Roma 16 26
    Milan 4 26
    -------------------
    Lazio 12 25
    Atalanta 7 25
    -------------------
    Napoli 9 24
    Torino 13 22
    Fiorentina 7 20
    Inter 2 18
    Chievoverona -1 18
    Sampdoria -3 18
    Genoa 0 16
    Bologna -5 16
    Cagliari -10 16
    Udinese -4 15
    Sassuolo -9 13
    Empoli -11 10
    -------------------
    Pescara -14 7
    Palermo -16 6
    Crotone -16 5

