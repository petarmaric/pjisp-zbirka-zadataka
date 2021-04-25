Paketi su opisani na sledeći način:

* sadržaj (jedna reč, maksimalno 30 karaktera)
* masa (realna vrednost, u kilogramima)
* lomljivo (jedna reč, "DA", ili "NE", maksimalno 2 karaktera)
  
Paketi se šalju putem kurirske službe, koja naplaćuje usluge slanja paketa u odnosu na njegovu masu.
Učitati pakete u jednostruko spregnutu listu (dodati novi element na kraj liste) i uraditi sledeće:

a) Izračunati cenu dostave paketa na osnovu sledećeg cenovnika:

+-----------+------+
| Masa [kg] | Cena |
+===========+======+
| 0-5       | 200  |
+-----------+------+
| 5-10      | 400  |
+-----------+------+

Ukoliko paket ima više od 10kg, dodatna masa paketa se naplaćuje pomnožena sa vrednošću argumenta komandne linije, koji predstavlja cenu po kilogramu.

b) Na standardni izlaz (ekran Terminala) ispisati sledeće informacije:

* sadržaj (ispisano sa ``%-10s`` format specifikatorom)
* lomljivo (ispisano sa ``%2s`` format specifikatorom)
* cena (zaokruženo na dve decimale, ispisano sa ``%6.2lf`` format specifikatorom)


Primer ulazne datoteke:

  .. literalinclude:: paketi.txt

Primer ispisa programa:

  .. literalinclude:: ispis.txt

Primer poziva programa:

  .. code:: bash

    ./paketi paketi.txt 5.5


