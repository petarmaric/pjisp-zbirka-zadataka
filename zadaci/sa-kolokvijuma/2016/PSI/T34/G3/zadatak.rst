Iz zadate ulazne datoteka učitati statički niz struktura,
pri čemu se struktura ``pacijent_st`` sastoji od sledećih polja:

- Ime (jedna reč, do 20 karaktera)
- Prezime (jedna reč, do 20 karaktera)
- Masa u kilogramima (prirodan broj)
- Visina u metrima (realan broj)

Kategorizacija indeksa telesne mase (:math:`BMI = \dfrac{masa}{visina^2}`):

.. tabularcolumns:: |R|L|

=================  ==================
Indeks             Dijagnoza
=================  ==================
       BMI < 18.5  Pothranjenost
18.5 ≤ BMI < 25.0  Idealna tezina
25.0 ≤ BMI < 30.0  Prekomerna tezina
       BMI ≥ 30.0  Gojaznost
=================  ==================

Formirati novi statički niz struktura i upisati ga u zadatu izlaznu datoteku,
pri čemu se struktura ``analiza_st`` sastoji od sledećih polja:

- Ime (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``pacijent_st``)
- Prezime (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``pacijent_st``)
- BMI (zaokružen na 2 decimale)
- Dijagnoza

Primer poziva::

	./bmi pacijenti.txt izvestaj.txt

sa zadatim ulazom u datoteci ``pacijenti.txt``::

	Homer  Simpson 150 1.83
	Skinny Pete     61 1.90
	Johnny Bravo    75 1.97
	Pizza  Lover    81 1.80

i očekivanim izlazom u datoteci ``izvestaj.txt``::

	Homer Simpson 44.79 Gojaznost
	Skinny Pete 16.90 Pothranjenost
	Johnny Bravo 19.33 Idealna tezina
	Pizza Lover 25.00 Prekomerna tezina
