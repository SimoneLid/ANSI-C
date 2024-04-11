#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
    printf("n arg:%d\nargv[1]:%s\n",argc,argv[1]);
    char *filename;
    filename = argv[1];
    open_txt(filename);
}



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