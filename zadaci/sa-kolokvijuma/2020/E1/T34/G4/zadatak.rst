Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``knjiga_st`` sastoji od sledećih polja:

- naziv knjige (jedna reč, do 20 karaktera)
- izdavač (jedna reč, do 20 karaktera)
- broj strana knjige (pozitivan ceo broj)

Na osnovu broja strana koje osoba može da pročita za sat vremena ``br_strana`` (pozitivan realan broj) formirati novi
statički niz struktura i upisati ga u zadatu izlaznu datoteku, pri čemu se
struktura ``duzina_citanja_st`` sastoji od sledećih polja:

- broj dana koji je potreban da se knjiga pročita ako osoba čita 24 sata dnevno (realan broj, zaokružen na 2 decimale, koristiti ``"%.2f"`` format specifikator)
- naziv knjige (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``knjiga_st``)

Primer poziva::

    ./knjige 11.5 knjige.txt duzina_citanja.txt

sa ``br_strana=11.5`` i zadatim ulazom u datoteci ``knjige.txt``:

.. literalinclude:: knjige.txt

i očekivanim izlazom u datoteci ``duzina_citanja.txt``:

.. literalinclude:: duzina_citanja.txt