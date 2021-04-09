Iz zadate datoteke učitati statički niz struktura, pri čemu se struktura mobilni_st sastoji od sledećih polja:

* naziv modela (jedna reč, do 30 karaktera)
* naziv marke (jedna reč, do 30 karaktera)
* cena telefona (realan broj)

Na osnovu zadatog niza struktura potrebno je ispisati sve one telefone čija je cena manja od zadate (parametar komandne linije), kao i ukupan broj takvih telefona. Rezultat je potrebno ispisati na standardni izlaz. Naziv ulazne datoteke i cena se prosleđuju kroz parametre komandne linije.

Primer poziva programa (``ulaz.txt`` predstavlja naziv ulazne datoteke, a ``50000`` je maksimalna zadata cena)::

    ./mobilni ulaz.txt 50000

Primer ulazne datoteke ``ulaz.txt``::

    Xiaomi Redmi_Note8 30000
    Samsung Galaxy_A7 43000
    Huawei P30 79999
    iPhone XR 69950

Primer ispisa na ekran::

    Naziv marke: Xiaomi, naziv modela: Redmi_Note8, iznos: 30000.00
    Naziv marke: Samsung, naziv modela: Galaxy_A7, iznos: 43000.00

    Ukupno postoji 2 modela koji su jefiniji od 50000.00 dinara.

