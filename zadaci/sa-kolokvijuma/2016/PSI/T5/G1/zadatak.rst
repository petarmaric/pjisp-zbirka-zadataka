Iz zadate ulazne datoteka učitati podatke u jednostruko spregnutu listu,
gde struktura ``meso_st`` sadrži sledeća polja:

- Skraćena oznaka grada (jedna reč, tačno 2 karaktera)
- Naziv vrste mesa (jedna reč, do 20 karaktera)
- Cena mesa po kilogramu (realan broj)

Naravno, struktura ``meso_st`` sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Na osnovu zadate vrste mesa ``vrsta_mesa`` upisati podatke iz formirane liste
u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture ``meso_st``:

- Cena mesa po kilogramu (zaokružena na 2 decimale, koristiti ``"%6.2f"`` format specifikator)
- Skraćena oznaka grada 
- Naziv vrste mesa

i potom u istu izlaznu datoteku upisati informaciju u kom gradu je zadata ``vrsta_mesa`` najpovoljnija.

Primer poziva::

	./povoljno_meso junetina cene_mesa.txt analiza.txt

sa ``vrsta_mesa=junetina``, zadatim ulazom u datoteci ``cene_mesa.txt``::

	NS svinjetina 429.99
	NS junetina   649.99
	BG junetina   639.99
	BG svinjetina 389.99
	NI svinjetina 439.99
	NI junetina   639.75

i očekivanim izlazom u datoteci ``analiza.txt``::

	429.99 NS svinjetina
	649.99 NS junetina
	639.99 BG junetina
	389.99 BG svinjetina
	439.99 NI svinjetina
	639.75 NI junetina

	Najpovoljnija 'junetina' je:
	639.75 NI junetina

Primer poziva kada tražena vrsta mesa ne postoji::

	./povoljno_meso teletina stare_cene_mesa.txt analiza.txt

sa ``vrsta_mesa=teletina``, zadatim ulazom u datoteci ``stare_cene_mesa.txt``::

	NS svinjetina 29.99
	BG svinjetina 35.99
	NI svinjetina 31.99

i očekivanim izlazom u datoteci ``analiza.txt``::

	 29.99 NS svinjetina
	 35.99 BG svinjetina
	 31.99 NI svinjetina

	Nigde nema 'teletina'!
