Iz zadate ulazne datoteke učitati podatke u binarno stablo, gde struktura ``projekcija_st`` sadrži sledeća polja:

- Skraćena oznaka grada (jedna reč, tačno 2 karaktera)
- Naziv bioskopa (jedna reč, do 10 karaktera)
- Naziv filma (jedna reč, do 8 karaktera)
- Naziv žanra (jedna reč, do 9 karaktera)
- Cena ulaznice (pozitivan realan broj)

Naravno, struktura ``projekcija_st`` sadrži i polja potrebna za pravilno formiranje binarnog stabla.

Na osnovu zadatog grada ``grad`` i žanra ``zanr``  iz formiranog binarnog stabla upisati podatke
u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``projekcija_st``:

- Skraćena oznaka grada (koristiti ``"%2s"`` format specifikator)
- Naziv bioskopa (koristiti ``"%-10s"`` format specifikator)
- Naziv filma (koristiti ``"%-8s"`` format specifikator)
- Naziv žanra (koristiti ``"%-9s"`` format specifikator)
- Cena ulaznice (zaokružena na 2 decimale, koristiti ``"%6.2f"`` format specifikator)

i potom u istu izlaznu datoteku upisati informaciju koja je projekcija najpovoljnija za zadati grad i žanr.

Primer poziva::

    ./povoljne_ulaznice NS Animated projekcije.txt analiza.txt

sa ``grad=NS``, ``zanr=Animated`` i zadatim ulazom u datoteci ``projekcije.txt``::

    NS Arena     Hobit   Fantasy  500.00
    NS Arena     Frozen  Animated 366.60
    NS Arena     Smurfs  Animated 399.90
    NS Arena     Gravity Sci-Fi   300.00
    BG Cineplexx Hobit   Fantasy  550.00
    BG Cineplexx Frozen  Animated 426.66
    BG Cineplexx Smurfs  Animated 429.99
    BG Cineplexx Gravity Sci-Fi   230.00

i očekivanim izlazom u datoteci ``analiza.txt``::

    BG Cineplexx  Gravity Sci-Fi   230.00
    NS Arena      Gravity Sci-Fi   300.00
    NS Arena      Frozen  Animated 366.60
    NS Arena      Smurfs  Animated 399.90
    BG Cineplexx  Frozen  Animated 426.66
    BG Cineplexx  Smurfs  Animated 429.99
    NS Arena      Hobit   Fantasy  500.00
    BG Cineplexx  Hobit   Fantasy  550.00

    Najpovoljnija projekcija za Animated filmove u NS je:
    Frozen 366.60

Primer poziva kada projekcija sa zadatim kriterijumima ne postoji::

    ./povoljne_ulaznice NS Horor projekcije_za_decu.txt analiza.txt

sa ``grad=NS``, ``zanr=Horor``, zadatim ulazom u datoteci ``projekcije_za_decu.txt``::

    NS Arena     Hobit   Fantasy  500.00
    NS 4Kids     Frozen  Animated 366.60
    NS 4Kids     Smurfs  Animated 399.90

i očekivanim izlazom u datoteci ``analiza.txt``::

    NS 4Kids     Frozen  Animated 366.60
    NS 4Kids     Smurfs  Animated 399.90
    NS Arena     Hobit   Fantasy  500.00

    Niko ne projektuje Horor filmove u NS!
