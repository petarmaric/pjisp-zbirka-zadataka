Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu. 
Podatke učitati u opadajućem redosledu po ceni proizvoda.
Struktura ``racun`` se sastoji od sledećih polja:

- šifra proizvoda (pozitivna celobrojna vrednost)
- naziv proizvoda (jedna reč, do 8 karaktera)
- cena proizvoda (realan broj)

Takođe, struktura ``racun`` sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Program treba da pomogne radniku da obriše stavke koje se greškom nalaze u ulaznoj datoteci i napravi završni račun.

Da bi radnik obrisao stavku sa računa potrebno je da preko terminala unese šifru proizvoda. 
Ukoliko stavka sa unetom šifrom postoji i ukoliko je uspešno obrisana, napisati na terminal obaveštenje "Uspešno ste uklonili stavku!", u suprotnom ispisati "Stavka sa unetom šifrom ne postoji!". Pogledati primer 3. 

Unos šifre proizvoda moguće je proizvoljan broj puta, sve dok radnik za šifru proizvoda ne unese -1. 
Kada korisnik unese -1 za šifru proizvoda, potrebno je u izlaznu datoteku ispisati stavke sa računa kao i ukupnu cenu svih proizvoda zaokruženu na dve decimale. Pogledati primer 4. 
Ukoliko je radnik obrisao sve proizvode a potom uneo šifru proizvoda -1. Ispisati u izlaznu datoteku "Racun je bez stavki". Pogledati primer 5.


Napomene:
- Kroz argumente komandne linije proslediti naziv ulazne datoteke i naziv izlazne datoteke.

1. Primer poziva::

   ./a.out racun.txt zavrsniRacun.txt
   
   
2. Zadati ulaz u datoteci ``racun.txt``:

  .. literalinclude:: racun.txt

3. 
   a) Primer unosa šifre proizvoda preko terminala i ispis poruke ukoliko radnik unese pogrešnu šifru::
    
   Unesite sifru proizvoda: 555
   Stavka sa unetom sifrom ne postoji!
   
   b) Primer unosa šifre proizvoda preko terminala i ispis poruke ukoliko radnik unese šifru koja se poklapa sa stavkom iz ulazne datoteke::
    
   Unesite sifru proizvoda: 111
   Uspešno ste uklonili stavku!
  
4. 
   a) Očekivani ispis u izlaznoj datoteci ukoliko radnik unese -1 za šifru proizvoda. (Izračunavanje ukupne cene i štampanje računa), a ukoliko je pre toga izvršio primer pod 3.a)::
   
   998 Paprika 289.00
   111 Gauda 250.00
   177 Paradajz 119.00
   200 Salvete 133.00
   123 Mleko 89.00
   100 Noblice 75.00
   
   Ukupna cena proizvoda je 935.00 din.
   
   b) Očekivani ispis u izlaznoj datoteci ukoliko radnik unese -1 za šifru proizvoda. (Izračunavanje ukupne cene i štampanje računa), a ukoliko je pre toga izvršio primer pod 3.b)::
   
   998 Paprika 289.00
   177 Paradajz 119.00
   200 Salvete 133.00
   123 Mleko 89.00
   100 Noblice 75.00
   
   Ukupna cena proizvoda je 658.00 din.
   

5. Očekivani ispis u izlaznoj datoteci ukoliko radnik obriše sve stavke sa računa, a potom unese -1 za šifru proizvoda. (Izračunavanje ukupne cene i štampanje računa)::

   Racun je bez stavki!


