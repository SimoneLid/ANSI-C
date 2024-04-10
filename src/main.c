#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Tuple
{
    char* name;
    int count;
    struct Tuple* next_tuple;
};

struct Word
{
    char* name;
    int count;
    struct Word* next_pointer_word;
    struct Tuple* tuple;
};

int main(int argc, char *argv[]){
    printf("n arg:%d\nargv[1]:%s\n",argc,argv[1]);
    char *filename;
    filename = argv[1];
    open_file(filename);
}




/* struct Word* ciao;
    ciao = (struct Word*) calloc(1, sizeof(struct Word));
    ciao->name="ciao";
    ciao->count=1;
    struct Word* domani;
    domani = (struct Word*) calloc(1, sizeof(struct Word));
    domani->name="domani";
    domani->count=1;
    ciao->next_pointer_word=domani;
    printf("parola:%s\ncount:%d\n",ciao->name,ciao->count);
    printf("puntatore dopo:%s\n",ciao->next_pointer_word->name);
    struct Tuple* prova;
    prova = (struct Tuple*) calloc(1, sizeof(struct Tuple));
    prova->name="prova";
    prova->count=1;
    ciao->tuple=prova;
    struct Tuple* prova2;
    prova2 = (struct Tuple*) calloc(1, sizeof(struct Tuple));
    prova2->name="piedi";
    prova2->count=1;
    ciao->tuple->next_tuple=prova2;
    printf("seconda tupla di %s:%s\n",ciao->name,ciao->tuple->next_tuple->name); */



/*
    controlla l'argomento che decide il compito
    e mette una variabile di controllo a true se è il 2 e a false se è l'1.
    Inoltre gestisce l'errore se nessuno dei due viene selezionato
    bool comp_control;
    if(*argv[1]=='1'){
        comp_control=false;
        printf("Eseguo il compito 1\n");
    }
    else if(*argv[1]=='2'){
        comp_control=true;
        printf("Eseguo il compito 2\n");
    }
    else{
        printf("Errore!\nNon è stato scelto un compito da eseguire tra l'1 e il 2\n");
        exit(0);
    }*/