U ulaznoj datoteci ``krediti.txt`` nalaze se:

- ime potražioca kredita (jedna reč, do 15 karaktera)
- prezime potražioca kredita (jedna reč, do 15 karaktera)
- vrsta kredita (jedna reč, do 8 karaktera)
- odobren (jedna reč, do 2 karaktera)
- iznos kredita (pozitivan, celobrojan broj)
- učešće (pozitivan, celobrojan broj)
- kamata (godišnja kamata, pozitivan realan broj, izražen u procentima)
- broj godina (pozitivan ceo broj, broj godina na koje je kredit uzet)

Ulazna datoteka krediti.txt::

    Dragan Dragic stambeni ne 3600000 500000 2.5 10
    Sava Tomic kes ne 7000000 20000 4 5
    Luka Lukic auto da 2606000 110000 5.99 5
    Tatjana Jovic auto da 1400000 0 7.5 7
    Teodor Matic kes ne 4500000 20000 5.99 11
    Nikola Nesic kes da 200000 0 8 3
    Milica Markovic stambeni ne 8000000 20000 2.5 4

Kroz argumente komandne linije proslediti vrstu kredita i naziv ulazne datoteke (Pogledati stavku 1.). 

Pronaći sve odobrene kredite određene vrste (vrste koju prosledite kao argument) i izračunati zaradu banke od odobrenih kredita. Rezultate ispisati u izlazni fajl <vrsta kredita iz argumenata>.txt pri čemu ukupnu zaradu treba ispisati na dve decimale. Ukoliko za datu vrstu kredita ne postoje odobreni krediti u izlaznu datoteku ispisati “Nema odobrenih kredita.” (Pogledati stavku 3.)

1. Primer poziva::

   ./a.out kes krediti.txt

2. Primer računanja zarade banke za jednu stavku::

    (iznos kredita – učešće) / 100 *  kamata * broj godina

3. Očekivani izlaz za odgovarajuću vrstu kredita:

a) primer izlazne datoteke za unetu vrstu kredita stambeni, u datoteci stambeni.txt::

    Nema odobrenih kredita.
    
b) primer izlazne datoteke za unetu vrstu kredita kes, u datoteci kes.txt::

    Nikola    Nesic    kes    da    200000    0    8    3 

    Ukupna zarada banke je 48000.00 din.