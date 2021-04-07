Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``slatkis_st`` sadrži sledeća polja:

- naziv slatkiša (jedna reč, do 30 karaktera)
- količina šećera na 100 grama (pozitivan realan broj)
- gramaža (pozitivan ceo broj)
- vrsta slatkiša (jedna reč, do 30 karaktera)

Naravno, struktura ``slatkis_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Na osnovu zadate vrste saltkiša ``vrsta`` iz formirane liste upisati podatke koji pripadaju zadatoj vrsti slatkiša u
zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``slatkis_st``:

- naziv slatkisa
- gramaža
- količina šećera na 100 grama

i potom u istu izlaznu datoteku upisati informaciju o slatkišu koji ima najveću količinu šećera u pakovanju.
Sve realne vrednosti zaokružiti na 2 decimale pri ispisu.

Primer poziva programa::

    ./slatkis praline slatkisi.txt izvestaj.txt

sa ``vrsta=praline`` i zadatim ulazom u datoteci ``slatkisi.txt``::

    Marzipan_log 54.2 100 marcipan
    Speculaas 28.6 600 keks
    Chocolate_pralines 52.9 125 praline
    Marzipan_rum 41.9 125 marcipan
    Zimmtsterne 43.5 175 keks
    Chocolate_cups 45.3 130 praline
    Marzipan_darm_chocolate 42.4 125 marcipan
    Cinnamon_rolls 56.8 220 pecivo

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    Chocolate_pralines 125 52.90
    Chocolate_cups 130 45.30

    Slatkis sa najvise secera je: Chocolate_pralines
    Kolicina secera je: 66.12