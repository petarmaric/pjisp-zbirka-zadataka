#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIZ 30
#define MAX_NAZIV 20+1

struct paket_st {
	char naziv_provajdera[MAX_NAZIV];
	char naziv_paketa[MAX_NAZIV];
	int mesecna_pretplata;
	int broj_besplatnih_poruka;
	double cena_po_poruci;
};

struct cena_st {
	double ukupna_cena;
	char naziv_provajdera[MAX_NAZIV];
	char naziv_paketa[MAX_NAZIV];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_pakete(FILE *in, struct paket_st paketi[], int *n);
double cena_paketa(struct paket_st paket, int mesecno_poruka);
void transform(struct paket_st paketi[], struct cena_st cene[], int n, int mesecno_poruka);
void snimi_cene(FILE *out, struct cena_st cene[], int n);


int main(int arg_num, char **args) {
	if (arg_num != 4) {
		printf("USAGE: %s MESECNO_PORUKA IN_FILENAME OUT_FILENAME\n", args[0]);
		exit(1);
	}

	int mesecno_poruka = atoi(args[1]);
	char *in_filename = args[2];
	char *out_filename = args[3];

	FILE *in  = safe_fopen(in_filename,  "r", 1);
	FILE *out = safe_fopen(out_filename, "w", 2);

	struct paket_st paketi[MAX_NIZ];
	struct cena_st cene[MAX_NIZ];
	int n;

	ucitaj_pakete(in, paketi, &n);
	transform(paketi, cene, n, mesecno_poruka);
	snimi_cene(out, cene, n);

	fclose(in);
	fclose(out);

	return 0;
}

FILE *safe_fopen(char filename[], char mode[], int error_code) {
	FILE *fp = fopen(filename, mode);
	if(fp == NULL) {
		printf("Can't open '%s'!", filename);
		exit(error_code);
	}
	return fp;
}

void ucitaj_pakete(FILE *in, struct paket_st paketi[], int *n) {
	*n = 0;
	while(fscanf(
		in, "%s %s %d %d %lf",
		 paketi[*n].naziv_provajdera,
		 paketi[*n].naziv_paketa,
		&paketi[*n].mesecna_pretplata,
		&paketi[*n].broj_besplatnih_poruka,
		&paketi[*n].cena_po_poruci
	) != EOF) {
		(*n)++;
	}
}

double cena_paketa(struct paket_st paket, int mesecno_poruka) {
	double base = paket.mesecna_pretplata;

	int extra_sms = mesecno_poruka - paket.broj_besplatnih_poruka;
	if (extra_sms > 0) {
		base += extra_sms * paket.cena_po_poruci;
	}
	
	return base;
}

void transform(struct paket_st paketi[], struct cena_st cene[], int n, int mesecno_poruka) {
	int i;
	for(i=0; i<n; i++) {
		strcpy(cene[i].naziv_provajdera, paketi[i].naziv_provajdera);
		strcpy(cene[i].naziv_paketa, paketi[i].naziv_paketa);

		cene[i].ukupna_cena = cena_paketa(paketi[i], mesecno_poruka);
	}
}

void snimi_cene(FILE *out, struct cena_st cene[], int n) {
	int i;
	for(i=0; i<n; i++) {
		fprintf(
			out, "%7.2f %s %s\n",
			cene[i].ukupna_cena,
			cene[i].naziv_provajdera,
			cene[i].naziv_paketa
		);
	}
}
