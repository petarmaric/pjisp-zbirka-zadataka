#include <stdio.h>

#define MAX_SIZE 30

int main() 
{
    int IntNiz[MAX_SIZE];
    char CharNiz[MAX_SIZE];
    char RezNiz[MAX_SIZE];
    int brIntNiz,brCharNiz,brRezNiz,i;
    int br=0;

    do {
        printf("Unesite broj elemenata niza IntNiz:");
        scanf("%d", &brIntNiz);
    } while(brIntNiz<=1 || brIntNiz > MAX_SIZE);

    for(i=0;i<brIntNiz;i++) 
    {
        do{
            printf("IntNiz[%d]=",i);
            scanf("%d", &IntNiz[i]);
        } while(IntNiz[i]<32||IntNiz[i]>126);
    }
    printf("\n\n");
    puts("Elementi niza IntNiz:");
    for(i=0; i<brIntNiz; i++) {
        printf("\nIntNiz[%d]=%d (%c)", i, IntNiz[i], IntNiz[i]);
    }
    printf("\n\n");

    do {
        printf("Unesite broj elemenata niza CharNiz:");
        scanf("%d", &brCharNiz);
    } while(brCharNiz<=1 || brCharNiz > MAX_SIZE);

    for(i=0;i<brCharNiz;i++) 
    {
        do{
            printf("CharNiz[%d]=",i);
            __fpurge(stdin);
            scanf("%c", &CharNiz[i]);
        } while(CharNiz[i]<32||CharNiz[i]>126);
    }
    printf("\n\n");
    puts("Elementi niza CharNiz:");
    for(i=0; i<brIntNiz; i++) {
        printf("\nCharNiz[%d]=%c (%d)", i, CharNiz[i], CharNiz[i]);
    }
    printf("\n\n");

    for(i=0;i<brIntNiz;brIntNiz++)
        for(j=0;j<brCharNiz;brCharNiz++)
        {
            if(CharNiz[j]=IntNiz)
        }

    return 0;
}