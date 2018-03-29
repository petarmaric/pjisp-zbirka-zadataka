Dat je niz ``A`` od maksimalno 10 celobrojnih elemenata.
Učitati ``n`` elemenata a zatim:

- učitati celobrojnu vrednost ``x``
- ispisati sadržaj celokupnog niza
- odrediti i ispisati verovatnoću da vrednost ``x`` bude odabrana slučajnim uzorkovanjem iz niza ``A`` (``chance``)

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``
- vrednost promenljive ``chance`` ispisati na 3 decimale

Za sledeće ulazne podatke::

    Unesite broj elemenata niza (max 10): 8
    Unesite trazenu vrednost: 42

    Unesite A[0]: 42
    Unesite A[1]: 5
    Unesite A[2]: 42
    Unesite A[3]: 1
    Unesite A[4]: -21
    Unesite A[5]: -42
    Unesite A[6]: 3
    Unesite A[7]: 42

očekivani izlaz je u sledećem formatu::

    A[0] = 42
    A[1] = 5
    A[2] = 42
    A[3] = 1
    A[4] = -21
    A[5] = -42
    A[6] = 3
    A[7] = 42

    found(A[0]) == 42
    found(A[2]) == 42
    found(A[7]) == 42

    chance = 0.375
