Dat je niz ``A`` od maksimalno 10 celobrojnih elemenata.
Učitati ``n`` elemenata a zatim:

- učitati pozitivnu celobrojnu vrednost ``x``
- ispisati sadržaj celokupnog niza
- odrediti koliko elemenata (počevši od kraja niza ka početku) je potrebno obuhvatiti da bi njihova suma bila veća od ``x``

Ograničenja:

- sprovesti zaštitu unosa nad podatkom ``n``
- smatrati da će suma celokupnog niza ``A`` uvek biti veća od ``x``

Za sledeće ulazne podatke::

    Unesite broj elemenata niza (max 10): 6
    Unesite trazenu vrednost: 4

    Unesite A[0]: 6
    Unesite A[1]: 5
    Unesite A[2]: 4
    Unesite A[3]: -3
    Unesite A[4]: 2
    Unesite A[5]: 1

očekivani izlaz je u sledećem formatu::

    A[0] = 6
    A[1] = 5
    A[2] = 4
    A[3] = -3
    A[4] = 2
    A[5] = 1

    sum(A[5]) == 1
    sum(A[4]) == 3
    sum(A[3]) == 0
    sum(A[2]) == 4
    sum(A[1]) == 9

    count = 5
