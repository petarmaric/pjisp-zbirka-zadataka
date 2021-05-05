**Prodavnica**

Iz zadate ulazne datoteke *artikli.txt* učitati podatke u jednostruko
spregnutu listu, gde struktura *artikal_st* sadrži sledeća polja:

-  *serijski_broj* (ceo broj),

-  *naziv (*\ jedna reč, maksimalno 13 karaktera\ *),*

-  *kolicina* (pozitivan ceo broj),

-  *jedinicna_cena* (realan broj) i

-  *ukupna_cena* (realan broj).

Struktura *artikal_st*, takođe sadrži i polja potrebna za pravilno
formiranje jednostruko spregnute liste. Prilikom formiranja jednostruko
spregnute liste voditi računa o tome da je potrebno elemente sortirati u
rastućem redosledu serijskog broja. Polje strukture *ukupna_cena*
izračunati na sledeći način: *ukupna_cena = kolicina \* jedinicna_cena*.

Potrebno je kupiti sve one artikle iz ponude prodavnice čiji zbir
ukupnih cena ne premašuje vrednost zadatog budžeta *budzet* . Nakon
uspešne kupovine, ispisati sve informacije o svim kupljenim artiklima.
Uz to, ispisati još i iznos preostalog budžeta i informaciju o broju
kupljenih artikala. Ako se ispostavi da je budžet nedovoljan za kupovinu
bilo kog artikla iz ponude, ispisati odgovarajuću poruku i izaći iz
programa sa izlaznim kodom 333.

Ako se za vrednost argumenta komandne linije *budzet* unese negativna
vrednost ispisati poruku o grešci i iz programa izaći sa izlaznim kodom
22.

Primer poziva:

./a.out 22800 artikli.txt

sa zadatim argumentom *budzet* *= 22800* i zadatim ulazom u
datoteci *artikli.txt*:

123.19 3 limun 2396

4399.99 25 trenerka 1179

109.11 8 tecni_sapun 7421

45.01 5 luk 7965

999.99 3 duks 4598

89.99 22 banane 8942

145.11 78 pasta_za_zube 1124

189.22 23 arf 3211

5899.39 7 pantalone 1698

215.49 13 ananas 1147

386.29 49 regenerator 3352

2354.99 15 farmerke 4452

i očekivanim ispisom na standardnom izlazu:

1124 pasta_za_zube 11318.58

1147 ananas 2801.37

2396 limun 369.57

3211 arf 4352.06

4598 duks 2999.97

7421 tecni_sapun 872.88

Uspesno ste kupili 6 proizvoda.

Na racunu vam je ostalo 85.57 din.

Ako se program pozove sa vrednošću *budzet* *= -250* ispis treba da bude
sledeći:

Budzet mora biti pozitivan broj!

Ako se program pozove sa vrednošću *budzet* *= 100* ispis treba da bude
sledeći:

Nemate dovoljno novca za kupovinu nijednog od proizvoda iz ponude!

Napomene:

-  Programski kod mora biti snimljen u okviru home direktorijuma, na
   predviđenom mestu

-  Nije dozvoljeno snimanje više kopija ili varijacija izvornog koda,
   samo jedna .c datoteka

-  Prilikom ispisa poštovati format očekivanog izlaza, prikazanom u
   tekstu zadatka

-  Nije dozvoljeno koristiti globalne promenljive

-  Organizovati kod u funkcije

-  Obratiti pažnju na odgovarajuće rukovanje greškama pri radu sa
   datotekama

-  Redosled argumenata komandne linije je veoma bitan i ne sme se
   menjati

-  Podaci se čitaju isključivo iz odgovarajuće datoteke (naziv ulazne
   datoteke je dat kroz argument komandne linije)

-  Sva dinamički zauzeta memorija mora biti oslobođena nakon korišćenja
