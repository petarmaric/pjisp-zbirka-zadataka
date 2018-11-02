Učitati broj članova reda (``n``) a zatim odrediti približnu vrednost broja 1
primenom sledeće matematičke formule:

.. math::
    1 \approx \sum_{i=0}^{n-1} \frac{1}{(i+1) (i+2)} = \frac{1}{1 \cdot 2} + \frac{1}{2 \cdot 3} + \frac{1}{3 \cdot 4} + \cdots + \frac{1}{n (n+1)}

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``
- sve realne promenljive trebaju biti tipa ``double``
- ne koristiti promenljive tipa niz

Za sledeće ulazne podatke::

    Unesite broj clanova reda: 5

očekivani izlaz je u sledećem formatu::

    clan[i=0] = 0.500000
    clan[i=1] = 0.166667
    clan[i=2] = 0.083333
    clan[i=3] = 0.050000
    clan[i=4] = 0.033333

    sum = 0.833333
