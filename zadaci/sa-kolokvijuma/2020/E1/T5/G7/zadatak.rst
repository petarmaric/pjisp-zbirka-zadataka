Iz zadate datoteke učitati podatke u jednostruko spregnutu listu (podaci se dodaju u sortiranom opadajućem poretku po broju bodova), 
pri čemu se struktura ``EKIPA`` sastoji od sledećih polja:

- naziv ekipe (jedna reč, do 20 karaktera)
- grad ekipe (jedna reč do 20 karaktera)
- broj bodova (ceo broj)


Naravno, struktura ``EKIPA`` sadrži i podatke potrebne za pravilno formiranje jednostruko spregnute liste. 
Potrebno je izračunati da li se prosleđena ekipa nalazi u gornjoj gornjoj ili donjoj polovini tabele. 
Na ekran je potrebno ispisati informacije o svim ekipama i odgovarajuću poruku za datu ekipu (pogledati primere). 
Kroz argumente komandne linije se prosleđuje naziv ulazne datoteke i ekipa za koju tražimo informacije.
      


Primer datoteke ``ulaz.txt``:

.. literalinclude:: ulaz.txt


Primer poziva 1::

    ./a.out ulaz.txt neka_ekipa

i očekivanim ispisom na standardnom izlazu:

.. literalinclude:: izlaz1.txt
    

Primer poziva 2::

    ./a.out ulaz.txt idemo_nis

i očekivanim ispisom na standardnom izlazu:

.. literalinclude:: izlaz2.txt


Primer poziva 3::

    ./a.out ulaz.txt zasto_ne

i očekivanim ispisom na standardnom izlazu:

.. literalinclude:: izlaz3.txt

