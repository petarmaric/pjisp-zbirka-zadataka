Napisati program koji učitava niz ``A`` od maksimalno 50 elemenata. 
Elementi niza predstavljaju četiri baze označene velikim slovima ``A``, ``G``, ``T`` i ``C``.
U niz uneti ``n`` elemenata poštujući ograničenja niza.
Nakon unosa elemenata:

  a. Pronaći procenat ponavljanja baze koju korisnik unese putem standardnog ulaza.
  b. Prebrojati i ispisati koliko se ukupno vodoničnih veza nalazi u unetom delu DNK, ako se za svaku bazu ``A`` i ``T`` kreiraju 2, 
     a za svaku bazu ``G`` i ``C`` kreiraju 3 vodonične veze.
  c. Kreirati novi niz odgovarajućeg paralelnog lanca kod kojeg se elementi niza A smenjuju po sledećim pravilima:

    - baza ``A`` zamenjuje se bazom ``T``, i obrnuto
    - baza ``G`` zamenjuje se bazom ``C``, i obrnuto

Za ulazni niz vrednosti ``[A, G, C, T, C, T, G, A, G]`` i unetu bazu ``G``, očekivani ispis na ekranu je::

        Baza G predstavlja 33% ovog lanca DNK.

        U unetom delu DNK nalazi se ukupno 23 vodonične veze.

        Paralelan lanac unetog DNK izgleda ovako:
          [T, C, G, A, G, A, C, T, C]
