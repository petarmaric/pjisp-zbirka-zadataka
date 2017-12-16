.. epigraph::
    U životu su izvesne samo dve stvari – smrt i porez.

    -- Bendžamin Frenklin (1706 - 1790)

Iz zadate ulazne datoteke učitati statički niz struktura, pri čemu se struktura
``poreska_stopa_st`` sastoji od sledećih polja:

- skraćena oznaka grada (jedna reč, tačno 2 karaktera)
- osnovni porez (prirodan broj)
- dodatni porez po kvadratu nekretnine (pozitivan realan broj)
- procenat poreskog popusta po članu domaćinstva (pozitivan realan broj)

Na osnovu površine nekretnine ``povrsina`` (pozitivan realan broj) i broja
članova domaćinstva ``clanova`` (prirodan broj) formirati novi statički niz
struktura i upisati ga u zadatu izlaznu datoteku, pri čemu se struktura
``porez_st`` sastoji od sledećih polja:

- skraćena oznaka grada (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``poreska_stopa_st``)
- ukupan porez bez popusta (zaokružen na 0 decimala, koristiti ``"%5.0f"`` format specifikator)
- ukupan porez sa popustom (zaokružen na 0 decimala, koristiti ``"%5.0f"`` format specifikator)

Primer poziva::

    ./porez 74.1 3 poreske_stope.txt porezi.txt

sa ``povrsina=74.1`` i ``clanova=3``, zadatim ulazom u datoteci ``poreske_stope.txt``::

    NS 1712 67.1 1.1
    NI  800 42.3 1.7
    BG 3270 98.6 1.5
    SU 1000 47.5 1.3

i očekivanim izlazom u datoteci ``porezi.txt``::

    NS  6684  6464
    NI  3934  3734
    BG 10576 10100
    SU  4520  4343
