Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu. Podatke učitati u 
rastućem redosledu po rednom broju rezervisanog sedišta.
Struktura ``balet`` sadrži sledeća polja:

- redni broj rezervisanog sedišta (pozitivna celobrojna vrednost)
- naziv baleta (jedna reč, do 8 karaktera)
- rezervisao (jedna reč, do 25 karaktera)
- cena (pozitivna celobrojna vrednost)

Takođe, struktura ``balet`` sadrži i polja potrebna za pravilno formiranje jednostruko spregnute 
liste.

Od korisnika zatražiti da unese naziv baleta (jedna reč, do 8 karaktera) i za uneti balet na 
terminal ispisati naziv baleta, ukupan broj prodatih karata i ukupnu cenu karata. Ispisati i 
podatke o rezervisanom sedištu, kupcu koji je rezervisao i ceni karte (ispoštovati očekivani izlaz prikazan u stavci pod rednim brojem 4.). 

Napomene:

- Prilikom unosa naziva baleta od strane korisnika voditi računa o tome da program treba da prepozna naziv baleta bez obzira na kombinaciju malih i velikih slova koje je korisnik uneo (pogledati stavku pod rednim brojem 2. npr. ukoliko korisnik unese „zizela”, u izlaznu datoteku treba ispisati informacije o prepoznatom baletu sa nazivom „Zizela”).
- Kroz argumente komandne linije proslediti naziv ulazne datoteke.
- Ukoliko za unete podatke od strane korisnika ne postoje podaci očekivan izlaz je prikazan u stavci pod rednim brojem 5.

1. Primer poziva::
.. code:: bash

   ./a.out balet.txt

2. Unos naziva baleta preko terminala::
    Naziv baleta: zizela

3. Zadati ulaz u datoteci balet.txt::

.. literalinclude:: balet.txt


4. Očekivani izlaz na terminal ukoliko postoje podaci::

    Ukupno prodatih karata za balet pod nazivom Zizela je 4.
    Ukupna zarada je 1120 dinara.

    Sediste: 3 Rezervisao: Igor Cena: 310 din
    Sediste: 5 Rezervisao: Nadezda Cena: 310 din
    Sediste: 10 Rezervisao: Ilija Cena: 250 din
    Sediste: 11 Rezervisao: Stefan Cena: 250 din

5. Očekivani izlaz na terminal ukoliko ne postoje podaci::
    
    Za unete podatke od strane korisnika ne postoje podaci.


