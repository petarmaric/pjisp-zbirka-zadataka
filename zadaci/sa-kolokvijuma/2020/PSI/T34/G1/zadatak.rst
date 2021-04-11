Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``caj_st`` sastoji od sledećih polja:

- naziv čaja (jedna reč, do 20 karaktera)
- minimalna količina kofeina u šoljici čaja (pozitivan ceo broj)
- maksimalna količina kofeina u šoljici čaja (pozitivan ceo broj)

Na standardni izlaz ispisati naziv čaja koji u proseku ima najviše kofeina i njegovu prosečnu količinu kofeina po šoljici (zaokruženu na 2 decimale upotrebom "%.2lf").
Prosek računati kao zbir minimalne i maksimalne količine kofeina u šoljici podeljen sa dva. Nije potrebno praviti dodatnu strukturu.

Primer poziva::

    ./a.out cajevi.txt

sa zadatim ulazom u datoteci ``cajevi.txt``::

    Zeleni 12 75
    Crni 40 125
    Beli 6 75
    Biljni 0 2

Očekivani ispis na standardnom izlazu::

    Crni 82.50