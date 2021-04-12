Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``kafa_st`` sadrži sledeća polja:

- naziv kafića (jedna reč, do 20 karaktera)
- vrsta kafe (jedna reč, do 20 karaktera)
- cena kafe (pozitivan realan broj)

Naravno, struktura ``kafa_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Na osnovu zadate vrste kafe ``vrsta_kafe`` iz formirane liste upisati podatke na
standardni izlaz (terminal), u sledećem rasporedu polja strukture ``kafa_st``:

- cena (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator)
- naziv vrste kafe
- naziv kafića

i potom u na standardni izlaz ispisati informaciju koja je prosečna cena zadate vrste kafe (zaokružena na 2 decimale, koristiti "%6.2f" format specifikator).

Primer poziva programa::

    ./kafica Espresso kafa.txt

sa ``vrsta_kafe=Espresso`` i zadatim ulazom u datoteci ``kafa.txt``::

    Caffe_City  Espresso   105.00
    Caffe_City  Macchiato  135.00
    Caffe_City  Cappuccino 145.00
    Caffe_Solo  Espresso   140.00
    Caffe_Solo  Macchiato  150.00
    Caffe_Solo  Cappuccino 160.00
    Caffe_Style Espresso   173.00
    Caffe_Style Macchiato  195.00
    Caffe_Style Cappuccino 215.00

i očekivanim izlazom ::

    105.00 Espresso   Caffe_City
    135.00 Macchiato  Caffe_City
    145.00 Cappuccino Caffe_City
    140.00 Espresso   Caffe_Solo
    150.00 Macchiato  Caffe_Solo
    160.00 Cappuccino Caffe_Solo
    173.00 Espresso   Caffe_Style
    195.00 Macchiato  Caffe_Style
    215.00 Cappuccino Caffe_Style

    Prosecna cena Espresso kafe je = 139.33

sa ``vrsta_kafe=Latte``::

    Latte kafa nije u ponudi!

