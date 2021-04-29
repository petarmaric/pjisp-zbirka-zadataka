Iz zadate datoteke učitati podatke u jednostruko spregnutu listu (podaci se dodaju u sortiranom redosledu na osnovu naziva filma), pri čemu se struktura ``film_st`` sastoji od sledećih polja:

- naziv filma (jedna reč, do 30 karaktera)
- cena ulaznice (realan broj)
- broj ulaznica (pozitivna celobrojna vrednost)


Naravno, struktura ``film_st`` sadrži i podatke potrebne za pravilno formiranje jednostruko spregnute liste. Potrebno je izračunati ukupnu zaradu po filmu, kao i ukupnu zaradu za sve filmove. Rezultat je potrebno ispisati na standardni izlaz. Naziv ulazne datoteke se prosleđuje kroz parametre komandne linije.

Primer poziva programa::

    ./a.out filmovi.txt

sa zadatim ulazom u datoteci ``filmovi.txt``::

    Pokajanje 250 8
    Hari_Poter_2 300 10
    Gospodar_prstenova_1 400 6
    Hari_Poter_4 400 30

i očekivanim ispisom na standardnom izlazu ::

    Naziv filma: Gospodar_prstenova_1, ukupna zarada: 2400.00
    Naziv filma: Hari_Poter_2, ukupna zarada: 3000.00
    Naziv filma: Hari_Poter_4, ukupna zarada: 12000.00
    Naziv filma: Pokajanje, ukupna zarada: 2000.00

    Ukupna ostvarena zarada je: 19400.00
