Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu listu, gde
struktura ``gorivo_st`` sadrži sledeća polja:

- skraćena oznaka grada (jedna reč, tačno 2 karaktera)
- tip goriva (jedna reč, do 10 karaktera)
- cena goriva (pozitivan realan broj)

Naravno, struktura ``gorivo_st`` sadrži i polja potrebna za pravilno formiranje
jednostruko spregnute liste.

Na osnovu zadatog tipa goriva ``tip_goriva`` (``gas``, ``benzin`` ili
``dizel``) iz formirane liste upisati podatke u zadatu izlaznu datoteku, u
sledećem rasporedu polja strukture ``gorivo_st``:

- cena (zaokružena na 2 decimale, koristiti ``"%6.2f"`` format specifikator)
- skraćena oznaka grada
- tip goriva

i potom u istu izlaznu datoteku upisati informaciju koja je prosečna cena
zadatog tipa goriva (zaokružena na 2 decimale, koristiti ``"%6.2f"`` format
specifikator).

Primer poziva::

    ./gorivo benzin cene.txt izvestaj.txt

sa ``tip_goriva=benzin`` i zadatim ulazom u datoteci ``cene.txt``::

    NS gas     71.90
    NS benzin 155.20
    NS dizel  165.15
    NI gas     69.30
    NI benzin 155.30
    NI dizel  165.20
    BG gas     70.20
    BG benzin 155.50
    BG dizel  165.40

i očekivanim izlazom u datoteci ``izvestaj.txt``::

     71.90 NS gas
    155.20 NS benzin
    165.15 NS dizel
     69.30 NI gas
    155.30 NI benzin
    165.20 NI dizel
     70.20 BG gas
    155.50 BG benzin
    165.40 BG dizel

    AVG = 155.33

Primer poziva kada gorivo sa zadatim kriterijumima ne postoji::

    ./gorivo gas mala_pumpa.txt izvestaj.txt

sa ``tip_goriva=gas`` i zadatim ulazom u datoteci ``mala_pumpa.txt``::

    SA benzin 196.90
    PE dizel  191.60

i očekivanim izlazom u datoteci ``izvestaj.txt``::

    196.90 SA benzin
    191.60 PE dizel

    NOT FOUND!
