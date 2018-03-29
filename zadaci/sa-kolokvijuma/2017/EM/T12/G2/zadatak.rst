Dat je niz ``A`` od maksimalno 10 pozitivnih celobrojnih elemenata.
Učitati ``n`` elemenata a zatim:

- ispisati sadržaj celokupnog niza
- proveriti da li postoje parovi elemenata za koje važi da su im poslednje cifre jednake

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``

Za sledeće ulazne podatke::

    Unesite broj elemenata niza (max 10): 8
    Unesite A[0]: 1234
    Unesite A[1]: 123
    Unesite A[2]: 12
    Unesite A[3]: 1
    Unesite A[4]: 21
    Unesite A[5]: 323
    Unesite A[6]: 4321
    Unesite A[7]: 6661999

očekivani izlaz je u sledećem formatu::

    A[0] = 1234
    A[1] = 123
    A[2] = 12
    A[3] = 1
    A[4] = 21
    A[5] = 323
    A[6] = 4321
    A[7] = 6661999

    last(A[1]) == last(A[5]) == 3
    last(A[3]) == last(A[4]) == 1
    last(A[3]) == last(A[6]) == 1
    last(A[4]) == last(A[6]) == 1

    count = 4
