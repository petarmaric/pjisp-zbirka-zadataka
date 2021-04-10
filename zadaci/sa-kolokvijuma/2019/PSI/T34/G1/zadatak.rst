Iz zadate ulazne datoteke učitati statički niz struktura maksimalne dužine 30, pri čemu se struktura
``kafa_st`` sastoji od sledećih polja:

- naziv kafe (jedna reč, do 20 karaktera)
- cena kafe (pozitivan realan broj)
- količina kofeina (pozitivan ceo broj)

Na osnovu zadate maksimalne dnevne doze kofeina koju student sme da popije pre ispita ``maksimalna dozvoljena količina kofeina`` (pozitivan ceo broj) formirati novi
statički niz struktura i upisati ga u zadatu izlaznu datoteku, pri čemu se struktura ``kafa_pred_ispit_st`` sastoji od sledećih polja:

- naziv kafe (koristiti funkciju ``strcpy`` prilikom kopiranja iz strukture ``kafa_st``)
- najveći broj kafa koju student sme da popije pred ispit, a da ne dostigne maksimalnu dozvoljenu količinu kofeina (pozitivan ceo broj)
- cena koju mora da plati da bi popio prethodno izračunati broj kafa (pozitivan realan broj)
- količina kofeina koja se unese ako se popije prethodno izračunati broj kafa (pozitivan ceo broj)

Ako kafa ima više kofeina od prosečne kafe (prosek izračunati u odnosu na sve kafe učitane iz ulazne datoteke), u izlaznoj datoteci ispisati ``UPOZORENJE, jaka kafa`` nakon ispisa te kafe.

Primer poziva::

    ./kafe kafa.txt kafa_pred_ispit.txt 230

sa ``maksimalna količina kofeina=230`` i zadatim ulazom u datoteci ``kafa.txt``::

    espresso        109.99  70
    coldBrew        215     225
    frenchPress     190     75
    moka            146.5   152
    domaca          80      55

i očekivanim izlazom u datoteci ``kafa_pred_ispit.txt``::

    espresso        3   329.97      210
    coldBrew        1   215.00      225    UPOZORENJE, jaka kafa
    frenchPress     3   570.00      225
    moka            1   146.50      152    UPOZORENJE, jaka kafa
    domaca          4   320.00      220
