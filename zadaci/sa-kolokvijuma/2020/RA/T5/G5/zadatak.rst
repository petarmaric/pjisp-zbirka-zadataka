Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``cvecara_st`` sadrži sledeća polja:

- naziv cvecare (jedna reč, do 20 karaktera)
- vrste cveca (jedna reč, do 20 karaktera)
- cena cveca (pozitivan realan broj)

Naravno, struktura ``cvecara_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Na osnovu zadate vrste cveca ``vrsta_cveca`` iz formirane liste ispisati podatke na
standardni izlaz (terminal), u sledećem rasporedu polja strukture ``cvecara_st``:

- cena (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator)
- naziv vrste cveca
- naziv cvecare

i potom na standardni izlaz (terminal) ispisati informaciju u kojoj cvecari je zadati cvet najpovoljniji i koja je njegova cena(zaokružena na 2 decimale).

Primer poziva programa::

    ./cvece Orhideja cvecare.txt

sa ``vrsta_cveca=Orhideja`` i zadatim ulazom u datoteci ``cvecare.txt``::

    Cvecara_Flowers Ruza     150.00
    Cvecara_Flowers Orhideja 800.00
    Cvecara_Flowers Ljiljan  720.00
    Cvecara_Sun     Ruza     200.00
    Cvecara_Sun     Orhideja 890.00
    Cvecara_Sun     Ljiljan  740.00
    Cvecara_Green   Ruza     260.00
    Cvecara_Green   Orhideja 650.00
    Cvecara_Green   Ljiljan  720.00

i očekivanim izlazom ::

    150.00 Ruza Cvecara_Flowers
    800.00 Orhideja Cvecara_Flowers
    720.00 Ljiljan Cvecara_Flowers
    200.00 Ruza Cvecara_Sun
    890.00 Orhideja Cvecara_Sun
    740.00 Ljiljan Cvecara_Sun
    260.00 Ruza Cvecara_Green
    650.00 Orhideja Cvecara_Green
    720.00 Ljiljan Cvecara_Green

    Cvecara sa najpovoljnijim cvetom Orhideja je Cvecara_Green, njena cena je 650.00

sa ``vrsta_cveca=Kala``::

    U trenutno raspolozivim cvecarama ne postoji cvet Kala!

