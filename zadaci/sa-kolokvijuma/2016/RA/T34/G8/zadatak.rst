Tačke u trodimenzionalnom Dekartovom koordinatnom sistemu opisane su preko njihovih koordinata:

* Vrednost na x-osi (realan broj dvostruke preciznosti)
* Vrednost na y-osi (realan broj dvostruke preciznosti)
* Vrednost na z-osi (realan broj dvostruke preciznosti)
* Rastojanje od koordinatnog početka (realan broj dvostruke preciznosti)

Učitati tačke iz ulazne datoteke, potom uraditi sledeće:

a. Prilikom učitavanja izračunati rastojanje od koordinatnog početka. 
   Nakon toga, zapisati koordinate u izlaznu datoteku čije ime se zadaje kao argument komandne linije u sledećem formatu:

      ``(x, y, z), d``

   ``x``, ``y`` i ``z``, redom, predstavljaju koordinate tačke, a ``d`` rastojanje od koordinatnog početka.
b. Pronaći najbližu i najdalju tačku tačku od koordinatnog početka.
   Izračunati njihovu međusobnu udaljenost, potom izračunati zapreminu kocke čija je stranica dužine udaljenosti između tih tačaka.
c. Izračunati zapreminu kocke čija stranica se unosi u program kao argument komandne linije (može biti realna vrednost).
   Upisati zapreminu iz prethodnog koraka i dobijenu zapreminu u izlaznu datoteku,
   kao zapreminu tela koje bi nastalo kada bi se od veće kocke odsekao deo veličine manje kocke.
   Izlazna datoteka treba da nosi ime koje počinje sa ``sracunata [argument]``, ``_kocka_minus_``, ``argument [sracunata]``, ``_kocka.txt``,
   gde će prva biti kocka sa većom, a druga kocka sa manjom zapreminom.

Primer poziva programa::

    ./a.out tacke.txt tacke_formatirano.txt 5

Primer ulazne datoteke ``tacke.txt``::

    1 1 1
    2 1 3
    4 1 7
    3 5 3
    7 7 7
    1 8 7

Očekivani sadržaj izlazne datoteke ``tacke_formatirano.txt``::

    (1.00, 1.00, 1.00), 1.73
    (2.00, 1.00, 3.00), 3.74
    (4.00, 1.00, 7.00), 8.12
    (3.00, 5.00, 3.00), 6.56
    (7.00, 7.00, 7.00), 12.12
    (1.00, 8.00, 7.00), 10.68

Očekivani sadržaj izlazne datoteke ``sracunata_kocka_minus_argument_kocka.txt``::

    Zapremina sracunate kocke: 1122.37
    Zapremina argument kocke: 125.00
    Razlika u zapreminama: 997.37

Korisne matematičke formule
---------------------------

Zapremina kocke
^^^^^^^^^^^^^^^

.. math::
   V = a ^ 3

Rastojanje između dve tačke u trodimenzionalnom koordinatnom sistemu
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. math::
   d = \sqrt {(x_2 - x_1) ^ 2 + (y_2 - y_1) ^ 2 + (z_2 - z_1) ^ 2}

