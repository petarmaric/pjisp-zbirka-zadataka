Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu. Podatke učitati u 
rastućem redosledu po šifri magacina.

Struktura ``magacin`` sadrži sledeća polja:

- šifra magacina (pozitivna celobrojna vrednost)
- šifra proizvoda (pozitivna celobrojna vrednost)
- naziv proizvoda (jedna reč, do 9 karaktera)
- cena (pozitivna celobrojna vrednost)


Takođe, struktura ``magacin`` sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Na terminal ispisati sve podatke iz ulazne datoteke. Potom od korisnika zatražiti da unese šifru magacina (pozitivna celobrojna vrednost) i šifru proizvoda (pozitivna celobrojna vrednost, poogledati stavku 3.). 
Za unete podatke na terminal ispisati šifru magacina, šifru proizvoda, ukupnu količinu i vrednost proizvoda (ispoštovati očekivani izlaz prikazan u stavci pod rednim brojem 4.). 

Napomene:

- Kroz argumente komandne linije proslediti naziv ulazne datoteke.
- Ukoliko za unete podatke od strane korisnika ne postoje podaci očekivan izlaz je prikazan u stavci pod rednim brojem 5.

1. Primer poziva::

   ./a.out magacin.txt

2. Zadati ulaz u datoteci magacin.txt:

  .. literalinclude:: magacin.txt

3. Ispis podataka na terminal i unos šifre magacina i šifre proizvoda preko terminala::
    
    123 11 maskica 900
    123 99 slusalice 470
    123 77 mis 1100
    123 11 maskica 900
    251 78 baterija 230
    251 75 punjac 750
    251 75 punjac 300
    954 30 kamera 1520

    Unesite sifru magacina: 123
    Unesite sifru proizvoda: 11

4. Očekivani izlaz na terminal ukoliko postoje magacin i proizvod::

    Ukupno proizvoda sa sifrom 11, pod nazivom maskica u magacinu sa sifrom 123 ima 2.
    Ukupna vrednost proizvoda je 1800 dinara.


5. Očekivani izlaz na terminal ukoliko ne postoje magacin i proizvod::
    
    Za unete podatke od strane korisnika ne postoje podaci.

