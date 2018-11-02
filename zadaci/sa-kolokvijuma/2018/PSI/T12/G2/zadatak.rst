Učitati broj članova reda (``n``) a zatim odrediti približnu vrednost broja 1/4
primenom sledeće matematičke formule:

.. math::
    \frac{1}{4} \approx \sum_{i=1}^n \frac{1}{i (i+1) (i+2)} = \frac{1}{1 \cdot 2 \cdot 3} + \frac{1}{2 \cdot 3 \cdot 4} + \frac{1}{3 \cdot 4 \cdot 5} + \cdots + \frac{1}{n (n+1) (n+2)}

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``
- sve realne promenljive trebaju biti tipa ``double``
- ne koristiti promenljive tipa niz

Za sledeće ulazne podatke::

    Unesite broj clanova reda: 5

očekivani izlaz je u sledećem formatu::

    clan[i=1] = 0.166667
    clan[i=2] = 0.041667
    clan[i=3] = 0.016667
    clan[i=4] = 0.008333
    clan[i=5] = 0.004762

    sum = 0.238095
