Stanovnici jednog grada su se pobunili zbog loših uslova života u divljim
naseljima:

.. figure:: propaganda.jpg
   :width: 75%
   :align: center

   Izvor: https://en.wikipedia.org/wiki/File:Jakarta_slumhome_2.jpg (CC BY 2.0)

Gradska vlast je stoga zamolila nezavisne lokalne novinare da sprovedu opsežno i
objektivno istraživanje, koje će *zasigurno* pokazati da je situacija na terenu
fina i ružičasta.
Nažalost, novinari su svoj zadatak doslovno shvatili:

.. figure:: propaganda@truth_factor=0.4.jpg
   :width: 75%
   :align: center

   ``truth_factor = 0.4``

Gradskim ocima se srećom ipak svideo ovakav način izveštavanja, samo su smatrali
da bi valjalo intenzivnije istaći realnost situacije na terenu:

.. figure:: propaganda@truth_factor=0.7.jpg
   :width: 75%
   :align: center

   ``truth_factor = 0.7``

Nažalost, nezahvalan narod se još uvek bunio te je stoga upotrebljen još viši
stepen algoritma za *optimizaciju percepcije* :sup:`TM`:

.. figure:: propaganda@truth_factor=1.0.jpg
   :width: 75%
   :align: center

   ``truth_factor = 1.0``

Zahvaljujući ovako naprednoj tehnologiji objektivnog izveštavanja gradska vlast
je najzad bila u mogućnosti da na jednostavan način široj javnosti pokaže da se
problem na kojem su izvesni remetilački faktori tako uporno insistirali ne može
primetiti ni u naznakama.

Novinari su pritom koristili sledeći algoritam za *optimizaciju percepcije*
:sup:`TM`::

    true_R = R * (1 - truth_factor) + 0xFC * truth_factor
    true_G = G * (1 - truth_factor) + 0x89 * truth_factor
    true_B = B * (1 - truth_factor) + 0xAC * truth_factor

Primer poziva programa::

    ./optimize-perception propaganda.bmp the-truth.bmp 0.7

sa ``truth_factor=0.7``, zadatim ulazom u datoteci ``propaganda.bmp`` i
očekivanim izlazom u datoteci ``the-truth.bmp``.

Ograničenja zadatka:

- svi nizovi moraju biti **dinamički alocirani**, upotrebom ``calloc`` funkcije
- sva dinamički zauzeta memorija mora biti oslobođena na odgovarajući način
