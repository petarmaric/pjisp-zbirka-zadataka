Proizvođač je prilikom razvoja svog novog modela CCD foto-senzora napravio
propust koji dovodi do "preslušavanja" između plavog i crvenog kanala slike,
zapisane u 24-bit RGB kolor formatu.
Pošto je ovaj problem uočen tek u kasnoj fazi razvoja, odlučeno je da će se
ipak nastaviti proizvodnja novog modela senzora, uz PR kampanju
*"It's not a bug; it's an undocumented feature!"*

Nezavisno od njih proizvođač profesionalnih fotoaparata sproveo je opsežno
marketinško istraživanje o novom senzoru i njegovoj nadrealnoj živosti boja,
ali ni uz silan uložen trud (i lobiranje) nažalost nije naišao na razumevanje
udruženja modnih fotografa.

Stoga je proizvođač fotoaparata svojim inženjerima dao zadatak da softverski
koriguju **plavi** kanal slike, primenom ``XOR`` bitwise operatora nad plavim i
crvenim kanalom.

Primer poziva programa::

    ./fix-colors cat-weird.bmp cat-fixed.bmp

sa zadatim ulazom u datoteci ``cat-weird.bmp``:

.. image:: cat-weird.*
   :width: 75%
   :align: center

i očekivanim izlazom u datoteci ``cat-fixed.bmp``:

.. image:: cat.*
   :width: 75%
   :align: center

Primer poziva programa::

    ./fix-colors dancers-weird.bmp dancers-fixed.bmp

sa zadatim ulazom u datoteci ``dancers-weird.bmp``:

.. image:: dancers-weird.*
   :width: 75%
   :align: center

i očekivanim izlazom u datoteci ``dancers-fixed.bmp``:

.. image:: dancers.*
   :width: 75%
   :align: center

Izvori slika:

- https://www.flickr.com/photos/waferboard/5436402112 (CC BY 2.0)
- https://www.flickr.com/photos/dfataustralianaid/10691296013 (CC BY 2.0)
