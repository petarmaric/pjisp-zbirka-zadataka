#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PREVOZNIK 30+1
#define MAX_STANJE 10+1
#define MAX_NIZ 10

typedef struct autobus_st
{
    char prevoznik[MAX_PREVOZNIK];
    char stanje[MAX_STANJE];
    double cena_karte;
    unsigned broj_mesta;
}Autobus;

FILE *otvori(char *name,char *mode)
{
    FILE *f = fopen(name,mode);

    if(f == NULL)
    {
        printf("Problem prilikom otvaranja %s datoteke.",name);
        exit(-2);
    }

    return f;
}

void ucitavanje(FILE *in, Autobus *a, int *n)
{
    *n=0;
    while(fscanf(in,"%s %s %lf %u",
                    a[*n].prevoznik,
                    a[*n].stanje,
                    &a[*n].cena_karte,
                    &a[*n].broj_mesta) != EOF)
    {
        (*n)++;
    }
}

void letovanje(FILE *out,Autobus *a, int n, int prijav_put,char *tr_prev)
{
    int i, suma=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(a[i].prevoznik,tr_prev) == 0 
            && strcmp(a[i].stanje,"ispravan") == 0)
        {
            suma+=a[i].broj_mesta;
        }
    }

    if(suma >= prijav_put)
    {
        fprintf(out,"\nPrevoznik %s na letovanje moze da preveze",tr_prev);
        fprintf(out," sve prijavljene putnike.");
    }
    else
    {
        fprintf(out,"\nPrevoznik %s ne moze da preveze",tr_prev);
        fprintf(out,"sve prijavljene putnike na letovanje!");
    }
}

void zarada(FILE *out,Autobus *a, int n)
{
    double suma=0.0;
    int i;

    for(i=0;i<n;i++)
    {
        suma+=a[i].cena_karte*a[i].broj_mesta;
    }
    fprintf(out,"\nMaksimalna moguca zarada svih autoprevoznika");
    fprintf(out," iznosi %.2lf dinara.",suma);
}

void ispis(FILE *out, Autobus *a,int n)
{
    fprintf(out,"Raspolozivi ispravni autobusi:\n\n");
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(a[i].stanje,"ispravan") == 0)
        {
            fprintf(out,"%s %s %.2lf %u\n",
                        a[i].prevoznik,
                        a[i].stanje,
                        a[i].cena_karte,
                        a[i].broj_mesta);
        }
    }
}

//primer poziva ./a.out Lasta autobusi.txt 138 obracun.txt
int main(int brojArgum, char **argumenti)
{
    Autobus a[MAX_NIZ];
    FILE *in,*out;
    char *trazeni_prevoznik = argumenti[1];
    int n, broj,prijavljeno_putnika=atoi(argumenti[3]);

    if(brojArgum != 5)
    {
        printf("Pogresan broj unetih argumenata!");
        exit(-1);
    }

    in = otvori(argumenti[2],"r");
    out = otvori(argumenti[4],"w");

    ucitavanje(in,a,&n);
    ispis(out,a,n);
    letovanje(out,a,n,prijavljeno_putnika,trazeni_prevoznik);
    zarada(out,a,n);

    fclose(in);
    fclose(out);

    return 0;
}
