Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde struktura ``pizza_st`` sadrži sledeća polja:

- Cena (prirodan broj)
- Skraćena oznaka države (jedna reč, tačno 3 karaktera)
- Skraćena oznaka grada (jedna reč, tačno 2 karaktera)
- Naziv pizze (jedna reč, do 20 karaktera)

Naravno, struktura ``pizza_st`` sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Na osnovu zadate oznake države ``drzava`` i naziva pizze ``naziv_pizze`` iz formirane liste upisati podatke
u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture pizza_st:

- Cena (koristiti ``"%4d"`` format specifikator)
- Skraćena oznaka države
- Skraćena oznaka grada
- Naziv pizze

i potom u istu izlaznu datoteku upisati informaciju u koliko gradova se može naći pizza pod zadatim kriterijumima.

Primer poziva::

    ./zad SRB Capricciosa pizze.txt analiza.txt

sa ``drzava=SRB``, ``naziv_pizze=Capricciosa`` i zadatim ulazom u datoteci ``pizze.txt``::

     510 SRB NS Capricciosa
     530 SRB NS Madjarica
    1270 SRB NS Prosciutto
     990 ITA NA Margharita
    1020 ITA NA Capricciosa
    1120 ITA NA Prosciutto
     540 SRB BG Capricciosa
     620 SRB BG Madjarica
     320 USA NY YankeeSlice

i očekivanim izlazom u datoteci ``analiza.txt``::

     510 SRB NS Capricciosa
     530 SRB NS Madjarica
    1270 SRB NS Prosciutto
     990 ITA NA Margharita
    1020 ITA NA Capricciosa
    1120 ITA NA Prosciutto
     540 SRB BG Capricciosa
     620 SRB BG Madjarica
     320 USA NY YankeeSlice

    count = 2
