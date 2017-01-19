Iz zadate ulazne datoteka učitati statički niz struktura,
pri čemu se struktura ``paket_st`` sastoji od sledećih polja:

- Naziv provajdera (jedna reč, do 20 karaktera)
- Naziv paketa (jedna reč, do 20 karaktera)
- Mesečna pretplata (prirodan broj)
- Broj besplatnih poruka uključenih u pretplatu (prirodan broj)
- Cena po poruci nakon potrošenih besplatnih poruka (realan broj)

Na osnovu zadatog mesečnog broja poruka ``mesecno_poruka`` (prirodan broj) formirati
novi statički niz struktura i upisati ga u zadatu izlaznu datoteku,
pri čemu se struktura ``cena_st`` sastoji od sledećih polja:

- Ukupna cena paketa (zaokružena na 2 decimale, koristiti ``"%7.2f"`` format specifikator)
- Naziv provajdera (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``paket_st``) 
- Naziv paketa (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``paket_st``)

Primer poziva::

	./sms 237 paketi.txt cene.txt

sa ``mesecno_poruka=237``, zadatim ulazom u datoteci ``paketi.txt``::

	mrs     belka50     360  50 3.89
	mrs     belka100    660 100 3.89
	mrs     belka150    900 150 3.89
	teleLOL premesi100  600 100 3.97
	teleLOL premesi220 1006 220 3.97
	vim     smaragd100  590 100 3.90
	vim     smaragd250  990 250 3.90

i očekivanim izlazom u datoteci :file:`cene.txt`::

	1087.43 mrs belka50
	1192.93 mrs belka100
	1238.43 mrs belka150
	1143.89 teleLOL premesi100
	1073.49 teleLOL premesi220
	1124.30 vim smaragd100
	 990.00 vim smaragd250
