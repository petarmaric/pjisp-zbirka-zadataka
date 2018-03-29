Dat je niz ``A`` od maksimalno 10 pozitivnih celobrojnih elemenata.
Učitati ``n`` elemenata a zatim:

- ispisati sadržaj celokupnog niza
- proveriti da li postoje parovi *susednih* elemenata za koje važi da su neparni

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``

Za sledeće ulazne podatke::

    Unesite broj elemenata niza (max 10): 8

    Unesite A[0]: 5
    Unesite A[1]: 3
    Unesite A[2]: 0
    Unesite A[3]: 4
    Unesite A[4]: 3
    Unesite A[5]: 7
    Unesite A[6]: 1
    Unesite A[7]: 15


očekivani izlaz je u sledećem formatu::

    A[0] = 5
    A[1] = 3
    A[2] = 0
    A[3] = 4
    A[4] = 3
    A[5] = 7
    A[6] = 1
    A[7] = 15

    odd(A[0]) == odd(A[1]) == 1
    odd(A[4]) == odd(A[5]) == 1
    odd(A[5]) == odd(A[6]) == 1
    odd(A[6]) == odd(A[7]) == 1

    count = 4
