Iz zadate ulazne datoteke automobili.txt učitati statički niz struktura, 
pri čemu se struktura ``automobil_st`` sastoji od sledećih polja:

- marka (jedna reč, do 20 karaktera)
- model (jedna reč, do 20 karaktera)
- vrsta servisa (jedna reč, do 20 karaktera)
- kubikaža (prirodan broj)
- budžet vlasnika (prirodan broj)

Vrsta servisa koji je potreban za automobil može biti MALI ili VELIKI. 
Budžet vlasnika predstavlja količinu novca koju je je vlasnik automobila
spreman da izdvoji za željeni servis.

Stvarna cena servisiranja automobile zavisi od vrste servisa i 
od kubikaže automobila. Cena servisiranja data je u tabeli ispod:

+---------------------+--------------------+----------------------+
| Kubikaža            | Cena malog servisa | Cena velikog servisa |
+=====================+====================+======================+
| kubikaza<1300       | 5 000              | 10 000               |
+---------------------+--------------------+----------------------+
| 1300<=kubikaza<1800 | 8 000              | 15 000               |
+---------------------+--------------------+----------------------+
| kubikaza>=1800      | 12 000             | 25 000               |
+---------------------+--------------------+----------------------+

Na standardni izlaz (terminal) ispisati sve automobile za koje se cena 
servisiranja uklapa u budžet vlasnika.

Primer poziva:

  .. code:: bash

    ./program automobili.txt

sa zadatim ulazom u datoteci ``automobili.txt``:

  .. literalinclude:: automobili.txt


i očekivanim izlazom na terminalu:

  .. literalinclude:: izlaz.txt
