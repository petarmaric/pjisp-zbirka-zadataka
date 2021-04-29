#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GR_LEN 31
#define SONG_LEN 51
#define ENG_LEN 7
#define ARRAY_LEN 20

typedef struct song{
    
    char group[GR_LEN];
    char name[SONG_LEN];
    char poreklo[ENG_LEN];
}SONG;


FILE* safe_open(char *name, char *mode){
    
    FILE *f = fopen(name, mode);
    if(f == NULL){
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }
    return f;
}

void read_songs(FILE *in, SONG *songs, int *n){


    while(fscanf(in, "%s %s %s", songs[*n].group, songs[*n].poreklo, songs[*n].name) != EOF)
        (*n)++;
}

void filter_songs(FILE *out, SONG *songs, int n, char *filter, char *value){

    int i;
    
    for(i=0; i<n; i++){
        if (strcmp(filter, "izvodjac")==0 && strcmp(value, songs[i].group)==0)
            fprintf(out, "%s %s %s\n", songs[i].group, songs[i].poreklo, songs[i].name);
        
        else if (strcmp(filter, "tip")==0 && strcmp(value, songs[i].poreklo)==0)
            fprintf(out, "%s %s %s\n", songs[i].group, songs[i].poreklo, songs[i].name);
    }

}

int main(int arg_num, char **args){

    SONG songs[ARRAY_LEN];
    int n = 0;
    
    if(arg_num != 3){
        printf("USAGE: %s FILTER VALUE\n", args[0]);
        exit(EXIT_FAILURE);
    }
    
    char *filter = args[1];
    char *value = args[2];
    FILE *in = safe_open("ulaz.txt", "r");
    FILE *out = safe_open("izlaz.txt", "w");
    
    read_songs(in, songs, &n);
    filter_songs(out, songs, n, filter, value);
    
    fclose(in);
    fclose(out);

    return 0;    
}
