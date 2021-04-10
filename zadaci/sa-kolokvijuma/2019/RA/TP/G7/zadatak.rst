Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde
struktura ``brownie_st`` sadrži sledeća polja:

- naziv namirnice (jedna reč, do 20 karaktera)
- potrebna količina namirnice za brownie (u gramima, pozitivan ceo broj)
- cena namirnice na 100g (u dinarima, realan broj)
- proizvođač (jedna reč, do 12 karaktera)

Naravno, struktura ``brownie_st`` sadrži i polja potrebna za pravilno
formiranje binarnog stabla.

Iz formiranog stabla upisati podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``brownie_st``:

- naziv namirnice
- potrebna količina namirnice za brownie
- ukupna cena namirnice (izračunati na osnovu količine namirnice i cene namirnice na 100g)

i potom u istu izlaznu datoteku upisati informaciju o ukupnoj ceni svih namirnica. Na osnovu zadatog proizvođača ``proizvođač`` u istu izlaznu datoteku upisati informaciju o namirnici koja ima najveću gramažu, a da je proizvodi izabrani proizvođač. Ako takva namirnica ne postoji, izostaviti ovaj ispis.

Namirnice ispisati u abecednom redu. Pri ispisu, realne brojeve zaokružiti na 3 decimale.


Primer poziva programa::

    ./brownie namirnice.txt izvestaj.txt Premia

sa zadatim ulazom u datoteci ``namirnice.txt``::

    crna_cokolada   250    139.99   Menaz
    puter           250    120      Premia
    jaja            80     55       Danubius
    secer           250    12.8     C
    brasno          30     11.99    Danubius
    kakao           30     78       C
    so              2      15.66    Premia

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    brasno          30     3.597
    crna_cokolada   250    349.975
    jaja            80     44.000
    kakao           30     23.400
    puter           250    300.000
    secer           250    32.000
    so              2      0.313

    Ukupna cena namirnica je: 753.285
    Namirnica sa najvecom gramazom proizvodjaca Premia je: puter