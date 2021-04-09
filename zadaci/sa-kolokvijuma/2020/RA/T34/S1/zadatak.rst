Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura ``parking`` sastoji od sledećih polja:

- naziv grada (jedna reč, do 30 karaktera)
- naziv zone (jedna reč, do 6 karaktera)
- registracija vozila (jedna reč, do 8 karaktera)
- broj provedenih sati (pozitivan broj)

+---------------------+--------------------+
| ZONA                | CENA PO SATU       | 
+=====================+====================+
| crvena              | 60 din             | 
+---------------------+--------------------+
| žuta                | 55 din             | 
+---------------------+--------------------+
| zelena              | 40 din             |
+---------------------+--------------------+
| plava               | 0 din              |
+---------------------+--------------------+

Napisati funkciju za računanje ukupne cene parkinga posebno za vozila koja se nalaze u crvenoj,
zelenoj i žutoj zoni. Izračunate vrednosti ispisati na terminal.
Kroz argumente komandne linije proslediti naziv ulazne datoteke.


Primer poziva:

.. code:: bash

    ./parking vozila.txt

sa zadatim ulazom u datoteci ``vozila.txt``:

.. literalinclude:: vozila.txt

i očekivanim ispisom na terminal:

.. literalinclude:: ispis.txt

