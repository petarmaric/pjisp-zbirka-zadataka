Dat je niz ``A`` od maksimalno 10 celobrojnih elemenata.
Učitati ``n`` elemenata a zatim:

- ispisati sadržaj celokupnog niza
- proveriti da li postoje parovi elemenata za koje važi da su po apsolutnoj vrednosti jednaki

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``

Za sledeće ulazne podatke::

    Unesite broj elemenata niza (max 10): 8
    Unesite A[0]: 1
    Unesite A[1]: 2
    Unesite A[2]: -2
    Unesite A[3]: -1
    Unesite A[4]: 3
    Unesite A[5]: 1
    Unesite A[6]: 2
    Unesite A[7]: -1

očekivani izlaz je u sledećem formatu::

    A[0] = 1
    A[1] = 2
    A[2] = -2
    A[3] = -1
    A[4] = 3
    A[5] = 1
    A[6] = 2
    A[7] = -1

    abs(A[0]) == abs(A[3]) == 1
    abs(A[0]) == abs(A[5]) == 1
    abs(A[0]) == abs(A[7]) == 1
    abs(A[1]) == abs(A[2]) == 2
    abs(A[1]) == abs(A[6]) == 2
    abs(A[2]) == abs(A[6]) == 2
    abs(A[3]) == abs(A[5]) == 1
    abs(A[3]) == abs(A[7]) == 1
    abs(A[5]) == abs(A[7]) == 1

    count = 9
