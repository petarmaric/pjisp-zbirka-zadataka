Proizvodi su opisani na sledeći način:

* Naziv (jedna reč, maksimalno 20 karaktera)
* vrsta (jedna reč, maksimalno 15 karaktera)
* cena (realan broj)
  
Za proizvode iz ulazne datoteke uraditi sledeće:

a) Učitati proizvode u jednostruko spregnutu listu. Novi elementi dodaju se tako da lista bude sortirana po ceni u rastućem redosledu.
b) Na osnovu argumenta komandne linije koji označava vrstu proizvoda, na standardni izlaz (ekran Terminala) ispisati sledeće informacije:

    * cena  (zaokruženo na dve decimale, ispisano sa ``%6.2lf`` format specifikatorom)
    * naziv (ispisano sa ``%-12s`` format specifikatorom)
    * vrsta (ispisano sa ``%s`` format specifikatorom)

Ispisati da proizvodi ne postoje u slučaju da nijedan proizvod nije zadate vrste (pogledati primere ispisa programa).

Primer ulazne datoteke:

.. literalinclude:: proizvodi.txt

Primer ispisa programa za postojeću zadatu vrstu proizvoda:

.. literalinclude:: ispis-postoji-vrsta.txt

Primer poziva programa za postojeću zadatu vrstu proizvoda:

.. code-block:: bash

  ./proizvodi proizvodi.txt prehrambeni

Primer ispisa programa za nepostojeću zadatu vrstu proizvoda:

.. literalinclude:: ispis-ne-postoji-vrsta.txt

Primer poziva programa za nepostojeću zadatu vrstu proizvoda:

.. code-block:: bash

  ./proizvodi proizvodi.txt odeca

