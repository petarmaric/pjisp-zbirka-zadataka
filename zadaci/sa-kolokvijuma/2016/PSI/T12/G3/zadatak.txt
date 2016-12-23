Dat je niz A od maksimalno 15 dvocifrenih prirodnih brojeva.
Učitati n elemenata a zatim proveriti da li postoje parovi elemenata za koje važi da je zbir kvadrata njihovih cifara jednak.
Sprovesti zaštitu unosa nad podatkom n.

Za sledeće podatke:
	n = 7
	A = {42, 67, 12, 36, 76, 29, 21}
očekivani izlaz je u sledećem formatu:
	A[0] = 42
	A[1] = 67
	A[2] = 12
	A[3] = 36
	A[4] = 76
	A[5] = 29
	A[6] = 21

	zbir(A[0]) = 20
	zbir(A[1]) = 85
	zbir(A[2]) = 5
	zbir(A[3]) = 45
	zbir(A[4]) = 85
	zbir(A[5]) = 85
	zbir(A[6]) = 5

	zbir(A[1]) == zbir(A[4]) == 85
	zbir(A[1]) == zbir(A[5]) == 85
	zbir(A[2]) == zbir(A[6]) == 5
	zbir(A[4]) == zbir(A[5]) == 85

	count = 4
