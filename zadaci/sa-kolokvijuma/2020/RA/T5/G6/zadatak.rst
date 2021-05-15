Iz zadate datoteke učitati podatke u jednostruko spregnutu listu (podaci se dodaju u sortiranom redosledu na osnovu naziva filma), pri čemu se struktura ``film_st`` sastoji od sledećih polja:

- naziv filma (jedna reč, do 30 karaktera)
- cena ulaznice (realan broj)
- broj ulaznica (pozitivna celobrojna vrednost)


Naravno, struktura ``film_st`` sadrži i podatke potrebne za pravilno formiranje jednostruko spregnute liste. Potrebno je izračunati ukupnu zaradu po filmu, kao i ukupnu zaradu za sve filmove. Rezultat je potrebno ispisati na standardni izlaz. Naziv ulazne datoteke se prosleđuje kroz parametre komandne linije.

Primer poziva programa:

    ./a.out filmovi.txt

sa zadatim ulazom u datoteci ``filmovi.txt``:

.. literalinclude:: ulaz.txt

i očekivanim ispisom na standardnom izlazu:

.. literalinclude:: izlaz.txt
