Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``knjiga_st`` sadrži sledeća polja:

- ime pisca (jedna reč, do 20 karaktera)
- prezime pisca (jedna reč, do 20 karaktera)
- naslov knjige (jedna reč, do 30 karaktera)
- zanr (jedna reč, do 20 karaktera)
- cena (pozitivan broj)

Naravno, struktura ``knjiga_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Učitati knjige u jednostruko spregnutu listu i uraditi sledeće:

#. Sortirati knjige po ceni u rastućem redosledu pri dodavanju u listu
#. Na standardni izlaz (ekran Terminala) ispisati sledeće informacije:

    - prezime pisca
    - ime pisca
    - cena
    - naslov knjige
	
#. Pronaći sve knjige za žanr koji je prosleđen kao argument komandne linije, sabrati cene tih knjiga i ispisati na standardni izlaz (ekran Terminala)

Primer poziva:

.. code:: bash

   ./knjige knjige.txt triler

sa zadatim ulazom u datoteci ``knjige.txt``:

.. literalinclude:: knjige.txt


i očekivanim izlazom na terminalu:

.. literalinclude:: izlaz.txt

