Učitati broj članova reda (``n``) a zatim odrediti približnu vrednost ``e``
primenom sledeće matematičke formule:

.. math::
    \frac{1}{e} \approx \sum_{i=0}^{n-1} \frac{(-1)^i}{i!} = \frac{1}{0!} - \frac{1}{1!} + \frac{1}{2!} - \frac{1}{3!} + \cdots + \frac{(-1)^{n-1}}{(n-1)!}

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``
- sve realne promenljive trebaju biti tipa ``double``
- ne koristiti promenljive tipa niz

Za sledeće ulazne podatke::

    Unesite broj clanova reda: 5

očekivani izlaz je u sledećem formatu::

    clan[i=0] =  1.000000
    clan[i=1] = -1.000000
    clan[i=2] =  0.500000
    clan[i=3] = -0.166667
    clan[i=4] =  0.041667

    sum = 0.375000

    e = 2.666667
