Iz zadate datoteke učitati statički niz struktura, pri čemu se struktura ``SONG`` sastoji od sledećih polja:

- naziv grupe (jedna reč, do 30 karaktera)
- naziv tipa (jedna reč, 6 karaktera)
- naziv pesme (jedna reč, ukupno do 50 karaktera)

      
Potrebno je u izlaznu datoteku filtrirati pesme na jedan od sledećih načina:

- ukoliko je kao parametar komandne linije prosleđen ``izvodjac``, radi se filtriranje po nazivu grupe;
- ukoliko je kao parametar komandne linije prosleđen ``tip``, radi se filtriranje po jezičkom poreklu pesme.

Tip filtera (izvođač ili tip) biće prosleđen kao drugi parametar komandne linije, a naziv filtera će biti prosleđen kao treći parametar. Podrazumeva se da će ulazna datoteka da se zove ``ulaz.txt``, a izlazna ``izlaz.txt``.


Primer datoteke ``ulaz.txt``:

.. literalinclude:: ulaz.txt

Primer poziva 1::

    ./a.out izvodjac azra

i očekivanim izlazom u datoteci ``izlaz.txt``:

.. literalinclude:: izlaz1.txt
    
Primer poziva 2::

    ./a.out tip strana

i očekivanim izlazom u datoteci ``izlaz.txt``:

.. literalinclude:: izlaz2.txt
