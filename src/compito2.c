#include "compito2.h"


/*
Inizializza il compito 2 monoprocesso creando la linked list e lanciando
la funzione che legge il file csv e scrive il file txt
*/
void comp2_mono(char *input, char *output, int n_word, char start_word[30]){
    char punct[30]=".";
    Word *first_word = create_first_word(punct);
    int pipes[2];
    read_csv(first_word,input,false,pipes);
    write_random_text(first_word,output,n_word,start_word);
}


/*
Inizializza il compito 2 multiprocesso creando la linked list e i tre processi
che comunicheranno tramite un pipe creato
*/
void comp2_par(char *input, char *output, int n_word, char start_word[30]){
    char punct[30]=".";
    Word *first_word = create_first_word(punct);
    int pipes[2];
    pipe(pipes);
    pid_t pid;
    if((pid=fork())>0){
        close(pipes[0]);
        read_csv(first_word,input,true,pipes);
    }
    else if(pid==0){
        close(pipes[1]);
        char preword[30];
        char postword[30];
        char perc[30];
        while(true){
            if(read(pipes[0],preword,30)!=30){
                break;
            }
            read(pipes[0],postword,30);
            read(pipes[0],perc,30);
            newTuple_perc(first_word,preword,postword,perc);
        }
        if((pid=fork())>0){
            wait(NULL);
        }
        else if(pid==0){
            write_random_text(first_word,output,n_word,start_word);
        }
        else{
            printf("Errore nella creazione di un processo tramite fork!\n");
            exit(1);
        }
    }
    else{
        printf("Errore nella creazione di un processo tramite fork!\n");
        exit(1);
    }
}