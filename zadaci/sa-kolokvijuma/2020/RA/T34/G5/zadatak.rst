Iz zadate ulazne datoteke učitatati statički niz struktura, pri čemu se struktura
rođendan_st sastoji od sledećih polja:

- Ime (jedna reč, do 15 karaktera),
- Dan rođenja (prirodan broj),
- Mesec rođenja (prirodan broj),
- Broj željenih parcadi torte(prirodan broj).


a) Napisati funkciju koja nalazi slavljenika (rođen na današnji dan), a zatim
   slavljeniku čestitati rođendan na standardni izlaz.
b) Napisati funkciju suma, koja vraća ukupan broj željenih parcadi torte.
c) Napisati funkciju koja sa standardnog ulaza uzima broj torti (t – prirodan broj) i
   proverava da li je broj torti dovoljan da bi svaki gost dobio željeni broj parčadi
   torte (jedna torta = 10 parčadi). Na standardni izlaz ispisati da li ima dovoljno
   torti na rođendanu



Primer poziva programa::

    ./a.out

Primer ispisa slavljenika (ako je rođen 5. 12.) ::

    Srecan rođendan Nikola!

Primer ispisa slavljenika (ako je rođen 6. 12.) ::

    Srećan rođendan Ana!

Primer ispisa da li ima dovoljno torti ::

    Za t=2
    Nema dovoljno torte!

    Za t=4
    Ima dovoljno torte!