====================
Temperatura u zgradi
====================

Temperatura u zgradi merena je na više različitih mesta ujutru, u podne i uveče.
U ulaznom fajlu ``merenja.txt`` redom su navedeni deo zgrade i tri merenja sprovedena tokom jednog dana.
Merenja su predstavljena na sledeći način:

* deo zgrade (jedna reč, maksimalno 20 karaktera)
* jutarnja temperatura (realna vrednost)
* podnevna temperatura (realna vrednost)
* večernja temperatura (realna vrednost)

Učitati merenja iz ulazne datoteke i uraditi sledeće:

a) Pronaći vrednost prosečne temperature za svaki deo zgrade. Ime dela zgrade i prosečnu temperaturu zaokruženu na jednu decimalu ispisati na standardni izlaz (ekran).
b) Pronaći deo zgrade sa maksimalnom vrednošću prosečne temperature i ispisati je zaokruženu na jednu decimalu na standardni izlaz (ekran).


Primer ulazne datoteke:

  .. literalinclude:: merenja.txt

Primer ispisa programa:

  .. literalinclude:: ispis.txt

Primer poziva programa:

  .. code:: bash

    ./temperatura merenja.txt


