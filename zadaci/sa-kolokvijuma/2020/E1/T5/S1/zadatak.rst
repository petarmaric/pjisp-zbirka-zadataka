

Iz zadate ulazne datoteke učitati podatke u jednostruko spregnutu
listu, pri čemu se struktura ``potrosnjaGasa_st`` sastoji od sledećih polja:

- prezime porodice (jedna reč, maksimalno 20 karaktera),
- vrsta stambene jedinice (jedna reč, maksimalno 4 karaktera - dozvoljene vrednosti su ``stan`` i ``kuca``),
- broj potrošenih kubika (realan broj),
- osnovna cena po kubiku (realan broj),
- cena po kubiku nakon što je pređena granica (realan broj) i
- ukupna cena (realan broj)

Struktura ``potrosnjaGasa_st`` dodatno sadrži i polje potrebno za formiranje jednostruko spregnute liste.

Na osnovu zadatog parametra *granica* iz formirane liste upisati podatke
u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``potrosnjaGasa_st``:

- broj potrošenih kubika,
- ukupna cena,
- vrsta stambene jedinice i
- prezime porodice

Ako je broj potrošenih kubika manji ili jednak vrednosti parametra ``granica``,
tada se ukupna cena računa kao proizvod broja potrošenih kubika i osnovne cene po kubiku.
U slučaju da je broj potrošenih kubika veći od vrednosti parametra ``granica``,
tada se ukupna cena računa na sledeći način:

ukupna_cena = granica * osnovna_cena_po_kubiku + (broj_potrošenih_kubika – granica) * cena_po_kubiku_nakon_što_je_pređena_granica

U istu izlaznu datoteku potrebno je ispisati još i sledeće informacije:

- prezime porodice čiji je mesečni račun najveći, a koja živi u vrsti stambene jedinice koja je prosleđena kao argument komandne linije,
- koliko će ukupno novčanih prihoda na mesečnom nivou ostvariti „Srbijagas“ nakon što sve porodice koje ne žive u vrsti stambene jedinice koja je prosleđena kao argument komandne linije plate svoj mesečni račun (izračunatu zaradu zaokružiti na dve decimale) i
- prosečan iznos mesečnog računa koji svaka porodica koja živi u vrsti stambene jedinice koja je prosleđena kao argument komandne linije treba da plati (izračunatu vrednost zaokružiti na dve decimale)

Primer poziva programa::

    ./zad 50.0 potrosnjaGasa.txt stan racun.txt

sa zadatim parametrom ``granica = 50.0``, zadatim ulazom u datoteci ``potrosnjaGasa.txt`` i sa zadatim
parametrom ``vrstaStambeneJedinice = stan``:

.. literalinclude:: potrosnjaGasa.txt

i očekivanim izlazom u datoteci ``racun.txt``:

.. literalinclude:: racun.txt