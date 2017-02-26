Napisati program koji učitava niz od maksimalno 40 elemenata.
U niz uneti ``n`` elemenata poštujući ograničenja niza.
Za unete elemente niza:

    a. Izračunati srednju vrednost elemenata niza i napraviti novi niz,
       gde pojedinačni elementi imaju vrednost kvadrata razlike početnog niza i njegove srednje vrednosti:

           novi_niz[i] = (pocetni_niz[i] - srednja_vrednost) :sup:`2`

       Ispisati dobijeni niz.
    b. Od niza dobijenog iz prethodnog koraka (pod a) izračunati srednju vrednost i njen kvadratni koren smestiti u promenljivu ``sigma``. 
       Iz originalnog niza (unetog sa tastature) ispisati vrednosti koje se nalaze u intervalu:

           ``[avg_orig - sigma, avg_orig + sigma]``,


       gde ``avg_orig`` predstavlja srednju vrednost originalnog niza.

Ispise realnih vrednosti zaokruživati na dve decimale.

Za ulazni niz vrednosti ``[6, 4.7, 1.7, 4.3, 3]``, očekivani ispis na ekranu je::

        [4.24, 0.58, 5.02, 0.13, 0.88]

        [4.70, 4.30, 3.00]


