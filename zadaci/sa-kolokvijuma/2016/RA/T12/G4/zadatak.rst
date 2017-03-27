Napisati program koji učitava niz ``A`` od maksimalno ``20`` celobrojnih, pozitivnih elemenata.
U niz uneti ``n`` elemenata poštujući ograničenja niza.
Nakon unosa elemenata:

  a. Izračunati harmonijsku sredinu niza i ispisati je.
  b. Prebrojati elemente deljive sa 3 na parnim indeksima i ispisati njihov ukupan broj.
  c. U novi niz B realnih elemenata uneti rešenja date funkcije gde je ``x`` element niza A i ispisati oba niza:

.. math::

    f(x) =
    \begin{cases}
        \frac{4}{x^2} + \frac{3}{x+1}   & \quad  0<x\leq 15\\
        4\sqrt[3]{x} + 4x - 3  & \quad 15<x\leq30 \\
        x^5  & \quad x>30 \\
    \end{cases}

Za ulazni niz vrednosti ``[1, 8, 26, 4, 6, 21, 17]`` očekivani ispis na ekranu je::

        Hs = 11.86

        Ukupan broj elemenata na parnim indeksima (indeksi pocinju od 1) deljivih sa 3 iznosi 1.

        A:  [1, 8, 26, 4, 6, 21, 17]
        B:  [5.50, 4.33, 112.85, 4.60, 4.43, 92.04, 75.29]
