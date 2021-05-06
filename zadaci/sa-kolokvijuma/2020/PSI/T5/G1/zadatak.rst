Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``knjiga_st`` sadrži sledeća polja:

- ime pisca (jedna reč, do 20 karaktera)
- prezime pisca (jedna reč, do 20 karaktera)
- naslov knjige (jedna reč, do 30 karaktera)
- cena po komadu (pozitivan broj)
- broj prodatih kopija (pozitivan broj)

Naravno, struktura ``knjiga_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Učitati knjige u jednostruko spregnutu listu i uraditi sledeće:

#. Sortirati knjige po ceni u rastućem redosledu pri dodavanju u listu
#. Izračunati ukupnu zaradu svake knjige korišćenjem cene po komadu i broja prodatih kopija.
#. Na standardni izlaz (ekran Terminala) ispisati sledeće informacije:
- prezime pisca
- ime pisca
- naslov knjige
- ukupna zarada
#. Pronaći knjigu koja je zaradila najviše novca i ispisati njene podatke na standardni izlaz (ekran Terminala)

Primer poziva:

.. code:: bash

   ./knjige knjige.txt

sa zadatim ulazom u datoteci ``knjige.txt``:

.. literalinclude:: knjige.txt


i očekivanim izlazom na terminalu:

.. literalinclude:: izlaz.txt

