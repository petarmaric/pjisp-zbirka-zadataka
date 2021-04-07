Napraviti program za vođenje evidencije bodova za društvene igre.
Igrači su predstavljeni na sledeći način:

* ime (jedna reč, maksimalno 20 karaktera)
* bodovi (celobrojna vrednost)

Na osnovu vrednosti argumenata komandne linije učitati pomoću tastature imena određenog broja igrača i postaviti im broj bodova na 0, zatim uraditi sledeće:

a) Za svaku partiju dodavati igračima osvojene bodove. Broj partija se unosi kao argument komandne linije.
b) Ispisati rezultate igre u izlazni fajl pod imenom ``bodovi.txt``.

Primer poziva programa (``2`` predstavlja broj igrača, a ``3`` broj odigranih partija):

  .. code:: bash

    ./bodovi 2 3

Primer rada programa:

  .. literalinclude:: u-programu.txt

Primer izlazne datoteke:

  .. literalinclude:: bodovi.txt




