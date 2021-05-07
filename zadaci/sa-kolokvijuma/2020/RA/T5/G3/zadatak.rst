

Iz zadate ulazne datoteke ``artikli.txt`` učitati podatke u jednostruko
spregnutu listu, gde struktura ``artikal_st`` sadrži sledeća polja:

- serijski_broj (ceo broj),
- naziv (jedna reč, maksimalno 13 karaktera),
- kolicina (pozitivan ceo broj),
- jedinicna_cena (realan broj) i
- ukupna_cena (realan broj).

Struktura ``artikal_st``, takođe sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste. Prilikom formiranja jednostruko
spregnute liste voditi računa o tome da je potrebno elemente sortirati u
rastućem redosledu serijskog broja. Polje strukture ``ukupna_cena``
izračunati na sledeći način: ``ukupna_cena = kolicina * jedinicna_cena``.

Potrebno je kupiti sve one artikle iz ponude prodavnice čiji zbir
ukupnih cena ne premašuje vrednost zadatog budžeta ``budzet`` . Nakon
uspešne kupovine, ispisati sve informacije o svim kupljenim artiklima.
Uz to, ispisati još i iznos preostalog budžeta i informaciju o broju
kupljenih artikala. Ako se ispostavi da je budžet nedovoljan za kupovinu
bilo kog artikla iz ponude, ispisati odgovarajuću poruku i izaći iz
programa sa izlaznim kodom 333.

Ako se za vrednost argumenta komandne linije ``budzet`` unese negativna
vrednost ispisati poruku o grešci i iz programa izaći sa izlaznim kodom
22.

Primer poziva::

    ./a.out 22800 artikli.txt

sa zadatim argumentom ``budzet = 22800`` i zadatim ulazom u
datoteci ``artikli.txt``:

.. literalinclude:: artikli.txt

i očekivanim ispisom na standardnom izlazu::

    1124 pasta_za_zube 11318.58
    1147 ananas 2801.37
    2396 limun 369.57
    3211 arf 4352.06
    4598 duks 2999.97
    7421 tecni_sapun 872.88

    Uspesno ste kupili 6 proizvoda.
    Na racunu vam je ostalo 85.57 din.

Ako se program pozove sa vrednošću ``budzet = -250`` ispis treba da bude
sledeći::

    Budzet mora biti pozitivan broj!

Ako se program pozove sa vrednošću ``budzet = 100`` ispis treba da bude
sledeći::

    Nemate dovoljno novca za kupovinu nijednog od proizvoda iz ponude!