Dat je niz ``A`` od maksimalno 10 celobrojnih elemenata.
Učitati ``n`` elemenata a zatim:

- ispisati sadržaj celokupnog niza, od poslednjeg elementa ka početnom
- odrediti i ispisati kvadratnu sredinu celokupnog niza (``KS``)
- odrediti i ispisati aritmetičku sredinu elemenata niza koji su na neparnim indeksima (``AS``)

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``
- sve realne promenljive trebaju biti tipa ``double``
- sve realne brojeve ispisivati zaokružene na 2 decimale

Za sledeće ulazne podatke::

    n = 5
    A = {4, 2, 6, -7, 1}

očekivani izlaz je u sledećem formatu::

    A[4] = 1
    A[3] = -7
    A[2] = 6
    A[1] = 2
    A[0] = 4

    KS = 4.60
    AS = -2.50

Korisne matematičke formule:

- kvadratna sredina niza :math:`KS = \sqrt{ \frac{1}{n} \sum {x_i}^2 }`
- aritmetička sredina niza :math:`AS = \frac{1}{n} \sum {x_i}`
