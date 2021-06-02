

Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu
listu, pri čemu se struktura ``taksi_st`` sastoji od sledećih polja:

- naziv_taksija (jedna reč, maksimalno 20 karaktera),
- vrsta_vozila (jedna reč, maksimalno 8 karaktera – dozvoljene vrednosti su ``limuzina`` i ``karavan``),
- cena_po_km (realan broj) i
- zauzetost (jedna reč, maksimalno 8 karaktera).

Struktura ``taksi_st`` dodatno sadrži i polje potrebno za formiranje jednostruko spregnute liste.

Na osnovu zadatog parametra ``novac`` i ``vrstaVozila`` iz formirane liste upisati podatke 
u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``taksi_st``:

- vrsta_vozila,
- naziv_taksija,
- cena_po_km i
- zauzetost.

Ako je ``zauzetost`` označena sa “+” neophodno je promeniti vrednost na ``slobodan``,
a ako je označena sa “-“ parametar ``zauzetost`` postaviti na vrednost ``zauzet``.

U istu izlaznu datoteku potrebno je ispisati još i sledeće informacije:
1. koji taksi će preći potencijalno najveću kilometražu na osnovu prosleđenog argumenta komandne linije ``novac``,
2. koliko će ukupno zaraditi kompanija od zauzetih taksija (na osnovu prosleđenog argumenta komandne linije ``novac``
koji je na raspolaganju za vožnju) ukoliko od svakog pređenog kilometra uzima 10%,
3. koliko ima taksija koji su slobodni i odgovaraju prosleđenom argumentu komandne linije ``vrstaVozila``.

Primer poziva programa::

    ./zad taxi.txt 2500 limuzina izvestaj.txt

sa zadatim parametrom ``novac = 2500``, zadatim ulazom u datoteci ``taxi.txt`` i sa zadatim
parametrom ``vrstaVozila = limuzina``:

.. literalinclude:: taxi.txt

i očekivanim izlazom u datoteci ``izvestaj.txt``:

.. literalinclude:: izvestaj.txt