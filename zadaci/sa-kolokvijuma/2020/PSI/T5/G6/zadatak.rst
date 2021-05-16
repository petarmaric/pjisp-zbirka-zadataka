Iz zadate datoteke učitati podatke u jednostruko spregnutu listu (podaci se dodaju na kraj liste), pri čemu se struktura ``rodjus_st`` sastoji od sledećih polja:

- naziv pića(jedna reč, do 30 karaktera)
- cena pića (realan broj)
- količina pića (pozitivan ceo broj)

Naravno, struktura ``rodjus_st`` sadrži i podatke potrebne za pravilno formiranje jednostruko spregnute liste. Potrebno je izračunati da li će moći da se kupe sva pića za unetu količinu novca (prosleđuje se kao parametar komandne linije, pogledati primere). Rezultat je potrebno ispisati na standardni izlaz. Naziv ulazne datoteke i količina novca se prosleđuje kroz parametre komandne linije.


Zadata datoteka ``ulazna.txt``:
    
.. literalinclude:: ulaz.txt

Primer poziva programa 1::

    ./a.out ulazna.txt 4000

i očekivanim ispisom na standardnom izlazu 1:

.. literalinclude:: izlaz1.txt
 
Primer poziva programa 2::

    ./a.out ulazna.txt 5000   

i očekivanim ispisom na standardnom izlazu 2:

.. literalinclude:: izlaz2.txt
