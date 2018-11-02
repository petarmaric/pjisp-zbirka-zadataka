Učitati broj članova reda (``n``) a zatim odrediti približnu vrednost ``pi``
primenom sledeće matematičke formule:

.. math::
    \frac{\pi^2}{8} \approx \sum_{i=1}^n \frac{1}{(2i-1)^2} = \frac{1}{1^2} + \frac{1}{3^2} + \frac{1}{5^2} + \cdots + \frac{1}{(2n-1)^2}

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``
- sve realne promenljive trebaju biti tipa ``double``
- ne koristiti promenljive tipa niz

Za sledeće ulazne podatke::

    Unesite broj clanova reda: 5

očekivani izlaz je u sledećem formatu::

    clan[i=1] = 1.000000
    clan[i=2] = 0.111111
    clan[i=3] = 0.040000
    clan[i=4] = 0.020408
    clan[i=5] = 0.012346

    sum = 1.183865

    pi = 3.077486
