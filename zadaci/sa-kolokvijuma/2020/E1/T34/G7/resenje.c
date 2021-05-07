#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIZ 30
#define MAX_ZAUZETOST 8+1
#define MAX_SIFRA 5+1

typedef struct sef_st
{
    char sifra[MAX_SIFRA];
    char zauzetost[MAX_ZAUZETOST];
    unsigned int cena_zakupa;
    double tezina_robe;
}Sef;

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

void ucitavanje(FILE *in, Sef *s, int *n)
{
    *n=0;
    while(fscanf(in,"%s %s %u %lf",
                    s[*n].sifra,
                    s[*n].zauzetost,
                    &s[*n].cena_zakupa,
                    &s[*n].tezina_robe) != EOF)
    {
        (*n)++;
    }
}

void srediPodatke(Sef *s, int n, double max_tez)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].tezina_robe > max_tez && strcmp(s[i].zauzetost,"zauzet") == 0)
        {
            s[i].cena_zakupa*=1.15;
        }
    }
}

int slobodni(Sef *s,int n)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].zauzetost,"slobodan") == 0)
        {
            count++;
        }
    }

    return count;
}

void ispisi(FILE *out, Sef *s, int n)
{
    int i;
    fprintf(out,"Cene sefova nakon oporezivanja:\n\n");
    for(i=0;i<n;i++)
    {    
        fprintf(out,"%s %s %u %.1lf\n",
                        s[i].sifra,
                        s[i].zauzetost,
                        s[i].cena_zakupa,
                        s[i].tezina_robe);
    }
    fprintf(out,"\nBroj slobodnih sefova: %d\n",slobodni(s,n));
}

//primer poziva ./a.out sefovi.txt 300 oporezovani.txt
int main(int brojArgum, char **argumenti)
{
    Sef s[MAX_NIZ];
    FILE *in,*out;
    double max_tezina = atof(argumenti[2]);
    int n, broj;

    if(brojArgum != 4)
    {
        printf("Pogresan broj unetih argumenata!");
        exit(-1);
    }

    in = otvori(argumenti[1],"r");
    out = otvori(argumenti[3],"w");

    ucitavanje(in,s,&n);
    srediPodatke(s,n,max_tezina);

    ispisi(out,s,n);

    fclose(in);
    fclose(out);
    return 0;
}
