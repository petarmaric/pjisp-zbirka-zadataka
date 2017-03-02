Tačke u dvodimenzionalnom Dekartovom koordinatnom sistemu opisane su preko njihovih
koordinata:

* Vrednost na x-osi (realan broj dvostruke preciznosti)
* Vrednost na y-osi (realan broj dvostruke preciznosti)

Učitati tačke iz ulazne datoteke, potom uraditi sledeće:

a. Pronaći koordinate težišne tačke za niz učitanih tačaka.
   Za pronalaženje koordinata težišne tačke potrebno je naći posebno aritmetičku sredinu x i y koordinata tačaka.
b. Pronaći sve tačke koje pripadaju krugu sa centrom u težišnoj tački i poluprečnika koji se unosi kao argument komandne linije (može biti realna vrednost).
   Rezultat ovog i prethodnog koraka upisati u izlaznu datoteku čiji se naziv sastoji od stringa ``pripada_krugu_poluprecnika_``,
   vrednost poluprečnika (argument komandne linije) i ekstenzijom ``.txt``.
c. Pronaći ukupan broj jedinstvenih trouglova koji može da nastane od datog niza tačaka.
   Da bi neke tri tačke sačinjavale trougao, potrebno je da duži koje one međusobno grade zadovoljavaju nejednakost trougla.
   Dobijeni broj trouglova upisati u izlaznu datoteku ``trouglovi.txt``.

Primer poziva programa::

    ./a.out tacke.txt 2

Primer ulazne datoteke ``tacke.txt``::

    1 1
    2 2
    3 1
    5 5
    6 1

Očekivani sadržaj izlazne datoteke ``pripada_krugu_poluprecnika_2.txt``::

    Krug poluprecnika 2.00 sa centrom u tacki (3.40, 2.00)

    (2.00, 2.00)
    (3.00, 1.00)

Očekivani sadržaj izlazne datoteke ``trogulovi.txt``::

    Broj trouglova: 8

Korisne matematičke formule
---------------------------

Računanje težišne tačke
^^^^^^^^^^^^^^^^^^^^^^^

Koordinate težišne tačke :math:`(x_T, y_T)` za n tačaka se računa na sledeći način:

    .. math::
       x_T &= \frac {(x_1 + x_2 + ... + x_n)} {n} \\
       y_T &= \frac {(y_1 + y_2 + ... + y_n)} {n}

Nejednakost trougla
^^^^^^^^^^^^^^^^^^^

Za svaki trougao sačinjen od stranica a, b i c, treba da važe sledeće nejednakosti:

    .. math::
       a + b > c, \\
       c + b > a, \\
       c + a > b

Rastojanje između dve tačke u dvodimenzionalnom koordinatnom sistemu
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Rastojanje između dve tačke :math:`(x_1, y_1)` i :math:`(x_2, y_2)` određuje se pomoću sledeće formule:

    .. math::
       d = \sqrt{(x_2 - x_1) ^ 2 + (y_2 - y_1) ^ 2}
