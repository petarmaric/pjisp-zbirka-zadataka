Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu,
gde struktura ``element_st`` sadrži sledeća polja:

- hemijski simbol (jedna reč, do 2 karaktera)
- ime (jedna reč, do 20 karaktera)
- atomska težina (prirodan broj)
- vrsta (jedna reč, do 20 karaktera)

Naravno, struktura ``element_st`` sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste.

Na osnovu zadate vrste hemijskog elementa ``vrsta`` iz formirane liste upisati
podatke u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture
``element_st``:

- hemijski simbol (koristiti ``"%-2s"`` format specifikator)
- atomska težina (koristiti ``"%3u"`` format specifikator)
- vrsta

i potom u istu izlaznu datoteku upisati informaciju o najtežem hemijskom
elementu koji pripada zadatoj ``vrsti``.

Primer poziva::

    ./najtezi metal uzorak_vino.txt analiza.txt

sa ``vrsta=metal``, zadatim ulazom u datoteci ``uzorak_vino.txt``::

    C  ugljenik  12 nemetal
    H  vodonik    1 nemetal
    O  kiseonik  16 nemetal
    Ca kalcijum  40 metal
    S  sumpor    32 nemetal
    Pb olovo    207 metal

i očekivanim izlazom u datoteci ``analiza.txt``::

    C   12 nemetal
    H    1 nemetal
    O   16 nemetal
    Ca  40 metal
    S   32 nemetal
    Pb 207 metal

    Najtezi metal je olovo (Pb), atomska tezina 207

Primer poziva kada tražena vrsta hemijskog elementa nije pronađena::

    ./najtezi halogen uzorak_voda.txt zagadjenost.txt

sa ``vrsta=halogen``, zadatim ulazom u datoteci ``uzorak_voda.txt``::

    H vodonik   1 nemetal
    O kiseonik 16 nemetal

i očekivanim izlazom u datoteci ``zagadjenost.txt``::

    H   1 nemetal
    O  16 nemetal

    U uzorku nije pronadjen nijedan halogen!
