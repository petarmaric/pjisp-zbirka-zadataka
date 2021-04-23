#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIZ 30
#define MAX_ZEMLJA 10+1
#define MAX_SIFRA 5+1
#define MAX_VREDNOST 4+1

typedef struct posiljka_st
{
    char sifra[MAX_SIFRA];
    char zemlja[MAX_ZEMLJA];
    char vrednost[MAX_VREDNOST];
    double tezina;
    double cena;
} Posiljka;

FILE *otvori(char *name,char *mode) {
    FILE *f = fopen(name,mode);
    
    if(f == NULL)
    {
        printf("Problem prilikom otvaranja %s datoteke.",name);
        exit(-2);
    }

    return f;
}

void ucitavanje(FILE *in, Posiljka *p, int *n)
{
    *n=0;
    while(fscanf(in,"%s %s %s %lf",p[*n].sifra,p[*n].vrednost,
            p[*n].zemlja,&p[*n].tezina) != EOF)
        (*n)++;
}

void srediPodatke(Posiljka *p, int n, char *zemlja)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        char temp_vrednost[MAX_VREDNOST] = " ";
        for(j=0;j<strlen(p[i].vrednost)-1;j++)
            temp_vrednost[j] = p[i].vrednost[j];

        if(atof(temp_vrednost) > 100 && p[i].tezina > 1000 
                && strcmp(p[i].zemlja,zemlja)==0)
            p[i].cena = atof(temp_vrednost)*1.18;
        else
            p[i].cena = atof(temp_vrednost);
    }
}

void sortiraj(Posiljka *p, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(strcmp(p[i].zemlja,p[j].zemlja) < 0)
            {
                Posiljka temp = p[i];
                p[i] = p[j];
                p[j] = temp;      
            }
}

void ispis(FILE *out, Posiljka *p, int n) 
{
    sortiraj(p,n);
    fprintf(out,"Cene posiljki nakon carinjenja:\n\n");
    int i;
    for(i=0;i<n;i++)
        fprintf(out,"%s %.2lf %s %s %.1lf\n",p[i].sifra,p[i].cena,
                p[i].zemlja,p[i].vrednost,p[i].tezina);
}

//primer poziva ./a.out posiljke.txt carinjenje.txt
int main(int brojArgum, char **argumenti)
{
    Posiljka p[MAX_NIZ];
    FILE *in,*out;
    char zemlja[MAX_ZEMLJA];
    int n, broj;

    if(brojArgum != 3)
    {
        printf("Pogresan broj unetih argumenata!");
        exit(-1);
    }

    in = otvori(argumenti[1],"r");
    out = otvori(argumenti[2],"w");

    printf("Uneti naziv zemlje: ");
    scanf("%s",zemlja);

    ucitavanje(in,p,&n);
    srediPodatke(p,n,zemlja);

    do
    {
        printf("Uneti broj (-1 - ispis na standardni izlaz");
        printf(" / 1 - ispis u datoteku): ");
        scanf("%d",&broj);
    }while(broj!=-1 && broj!=1);

    if(broj==-1)
        ispis(stdout,p,n);
    else
        ispis(out,p,n);

    fclose(in);
    fclose(out);
  
    return 0;
}

