Podešavanja repozitorijuma i dodavanje novih zadataka
=====================================================

Fork repozitorijuma
-------------------

* Otići na `repozitorijum zbirke <https://github.com/petarmaric/pjisp-zbirka-zadataka>`_ i odabrati opciju ``Fork``
* Rezultat će biti kopija repozitorijuma na vašem profilu. Klonirati taj repozitorijum preko HTTPS konekcije:

.. code-block:: bash

  git clone https://github.com/<ime-profila>/pjisp-zbirka-zadataka.git
  
Ili preko SSH (preporuka je da podesite vaš git da radi na `ovaj način <https://docs.github.com/en/enterprise-server@2.22/github/authenticating-to-github/connecting-to-github-with-ssh>`_):

.. code-block:: bash

  git clone git@github.com:<ime-profila>/pjisp-zbirka-zadataka.git

Podešavanje upstream grane
--------------------------

Nakon kloniranja lokalnog fork-a, biće podešen ``remote origin`` ``URL`` na lokalni fork.
Ono što je neophodno da bi lokalni fork bio ažuriran najnovijom verzijom zbirke je podešavanje tzv. ``upstream`` grane.
To se vrši na sledeći način, preko HTTPS:

.. code-block:: bash

  git remote add upstream https://github.com/petarmaric/pjisp-zbirka-zadataka.git

Ili preko SSH:

.. code-block:: bash

  git remote add upstream git@github.com:petarmaric/pjisp-zbirka-zadataka.git

Ažuriranje fork-a sa promenama na originalnom repozitorijumu
------------------------------------------------------------

Na master grani uraditi sledeće (provera da li ste na master grani vrši se pomoću komande ``git branch``)

.. code-block:: bash

  git pull upstream master
  git push origin master

Prva komanda ažurira lokalni git repozitorijum najnovijem stanjem sa originalnog repozitorijuma.
Druga komanda to novo stanje propagira na fork-ovani Github repozitorijum.

Dodavanje novih zadataka
------------------------

Važno: Pre dodavanja zadataka obavezno izvršiti `Ažuriranje fork-a sa promenama na originalnom repozitorijumu`_!

Pre nego što krenete u pripremu zadatka za zbirku, podsetite se šta su `Česte greške`_.

Napraviti novu granu sa smislenim nazivom (zadatka, ili zadataka koje dodajete, na primer ``2020-EE-T1234-G1``):

.. code-block:: bash

  git branch <ime-grane>
  git checkout <ime-grane>

Zatim dodate fajlove i komitujete ih (preporuka je da stalno koristite ``git status`` da biste bili skroz sigurni šta radite):

.. code-block:: bash

  git add <putanja-do-vaših-zadataka>
  git commit --all -m "zadaci: Dodat tekst zadatka sa kolokvijuma <godina smer kolokvijum grupa>"

Nakon uspešnog commit-a, potrebno je kreirati istu granu i na lokalnom fork-u:

.. code-block:: bash

  git push -u origin <ime-grane>

Opcija -u kreiraće istoimenu granu i na origin repozitorijumu (vašem fork-u).

Provera izgleda zadatka
-----------------------

Više nije neophodno instalirati Python, Docker i sve propratne alate u lokalu da biste videli kako zbirka izgleda.
Dodata je Github akcija, pomoću koje možete proveriti kako vaš zadatak izgleda u HTML i PDF verziji zbirke.
Nakon push-a na vaš repozitorijum, idite na tab ``Actions``, odaberite željeni commit kliknite na ``build``.
Videćete indikator uspešnosti nakon vaših promena. Ukoliko je sve uspešno, stajaće zeleni kružić.
Ukoliko imate crveni kružić, znači da korak ``Build zbirka`` nije uspeo i možete detaljno pogledati gde ste pogrešili.

Ako je sve prošlo kako treba, u sekciji ``Summary`` (gore, s leve strane), u sekciji ``Artifacts`` biće zbirka za download.
U pitanju je zip, koji ima PDF verziju zbirke i HTML verziju zbirke. HTML verziju otvarate tako što uđete u direktorijum ``html`` i otvorite fajl ``zbirka.html``.
Obavezno proveriti da li su vaši zadaci dobro formatirani u obe verzije!

Kreiranje Pull Request-a
------------------------

* Na fork-u repozitorijuma izabrati ``Pull Requests``, zatim ``New pull request``.
* Na vašem repozitorijumu izabrati vašu novu granu (opcija skroz desno) i ukoliko nemate konflikata sa repozitorijumom, napraviti novi Pull Request

Revizija zadatka i naknadne promene
-----------------------------------

Ukoliko ste primetili da ste negde pogrešili, ili ako vam tokom review-a bude zatraženo da nešto ispravite,
ispravku ćete uraditi kao novi commit na granu koju ste označili za Pull Request:

.. code-block:: bash

  git commit --all -m "<kratak opis ispravke>"
  git push origin <ime-grane-za-pr>

Ukoliko ste sve uradili kako treba, vaš Pull Request biće ažuriran novim commit-om.
Nakon što ste zadovoljni vašom ispravkom, označiti Pull Request kao `ready for review` i sačekati odobrenje od review-era.

Odobren Pull Request
--------------------

Ukoliko je vaš Pull Request odobren, možete obrisati granu sa fork-ovanog repozitorijuma tako što ćete otići na `Pull requests <https://github.com/petarmaric/pjisp-zbirka-zadataka/pulls>`_ sekciju i u ``Closed`` sekciji odabrati vaš odobreni Pull Request. Na dnu će vam biti dostupna opcija ``Delete branch``, koja će obrisati granu sa vašeg fork-a na Github-u.

Grana na lokalnom repozitorijumu briše se na sledeći način: ``git branch -d <ime-grane-za-pr>``
Nakon toga, ne bi bilo loše da izvršite `Ažuriranje fork-a sa promenama na originalnom repozitorijumu`_, kako biste imali najnoviju verziju originalnog repozitorijuma.

Česte greške
------------

U kodu referentnog rešenja, dužina jedne linije ne sme preći 80 karaktera!
  Ukoliko vaša naredba prelazi zadato ograničenje, smisleno je prelomiti u više redova. Obavezno kompajlirati i pokrenuti rešenje nakon intervencije.

Očekivana identacija (uvlačenje) koda je 4 space karaktera. 
  Rešenja sa tab karakterima neće proći build fazu.
  Ukoliko trenutno rešenje ima tabove, vaš omiljeni editor sigurno ima način da ih zameni sa odgovarajućim brojem space karaktera.
  Potražite na internetu kako se to radi. U nastavku je prikazano kako se to može proveriti u okviru Linux Terminala.

  U okviru Terminala, proverite da li vaš kod ima tabova: ``cat -T resenje.c`` (na mestu tabova, biće ispisano ``^I``)

  Konverziju u space karaktere možete uraditi pomoću komande: ``expand -t4 resenje.c > resenje-with-spaces.c``

  Potom, zamenu originalnog fajla uraditi na sledeći način: ``mv resenje-with-spaces.c resenje.c``

Ukoliko postavljate ulazni i izlazni fajl (ili ispis programa u fajlu), referencirajte ih.
  U okviru teksta zadatka, koristeći ``.. literalinclude:: ime-fajla.txt`` direktivu.

  Tako obezbeđujete jedan izvor podataka, odnosno, eliminišete šansu da napravite grešku prilikom kopiranja sadržaja datoteke u tekst zadatka.
  Ono što vaš program obradi i rezultat njegovog rada će biti i u samom tekstu zadatka.
  Niste u obavezi da uz rešenje prilažete ulazni i izlazni fajl, ali u samom tekstu zadatka se mora naći barem jedan primer.

Izaberite i pridržavajte se jedne kodne konvencije (stila).
  Nemojte mešati više različitih konvencija u okviru jednog rešenja.
  To je primer loše prakse kodiranja. Zbirka nema uređen coding style, stoga za šta god da se odlučite, a da iole ima smisla, biće prihvaćeno.

