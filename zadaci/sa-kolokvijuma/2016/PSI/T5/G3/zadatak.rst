Iz zadate ulazne datoteka učitati podatke u jednostruko spregnutu listu,
gde struktura igra_st sadrži sledeća polja:
- Naziv igre (jedna reč, do 10 karaktera)
- Naziv žanra (jedna reč, do 8 karaktera)
- Naziv platforme (jedna reč, do 8 karaktera)
- Cena igre (pozitivan realan broj)
Naravno, struktura igra_st sadrži i polja potrebna za pravilno formiranje jednostruko spregnute liste.

Na osnovu zadate platforme platforma i žanra zanr upisati podatke iz formirane liste
u zadatu izlaznu datoteku, u sledećem rasporedu polja strukture igra_st:
- Naziv igre (koristiti "%-10s" format specifikator)
- Naziv žanra (koristiti "%-8s" format specifikator)
- Naziv platforme  (koristiti "%-8s" format specifikator)
- Cena igre (zaokružena na 2 decimale, koristiti "%5.2f" format specifikator)
i potom u istu izlaznu datoteku upisati informaciju koja je igra najpovoljnija za zadatu platformu i žanr.

Primer poziva:
	./povoljne_igre PC Sandbox igre.txt analiza.txt
sa platforma=PC, zanr=Sandbox i zadatim ulazom u datoteci igre.txt:
	Dota2      MOBA     PC        0.00
	Fallout3   RPG      PC       19.99
	Minecraft  Sandbox  PC       19.95
	Minecraft  Sandbox  PS3      18.99
	Minecraft  Sandbox  Android   5.49
	Factorio   Sandbox  PC       12.50
i očekivanim izlazom u datoteci analiza.txt:
	Dota2      MOBA     PC        0.00
	Fallout3   RPG      PC       19.99
	Minecraft  Sandbox  PC       19.95
	Minecraft  Sandbox  PS3      18.99
	Minecraft  Sandbox  Android   5.49
	Factorio   Sandbox  PC       12.50

	Najpovoljnija 'Sandbox' igra za PC platformu je:
	Factorio 12.50

Primer poziva kada igra sa zadatim kriterijumima ne postoji:
	./povoljne_igre Atari MOBA stare_igre.txt analiza.txt
sa platforma=Atari, zanr=MOBA, zadatim ulazom u datoteci stare_igre.txt:
	Pong       Arcade   Atari     0.00
	Breakout   Arcade   Atari     1.20
i očekivanim izlazom u datoteci analiza.txt:
	Pong       Arcade   Atari     0.00
	Breakout   Arcade   Atari     1.20

	Za Atari platformu ne postoje 'MOBA' igre!
