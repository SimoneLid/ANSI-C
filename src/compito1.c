#include "compito1.h"

/*
Inizializza il compito 1 monoprocesso creando la linked list e lanciando
la funzione che legge il file txt e scrive il file csv
*/
void comp1_mono(char *input, char *output){
    char point[30]=".";
    Word *first_word=create_first_word(point);
    int pipes[2];
    read_txt(first_word,input,false,pipes);

    // controlla che esista almeno una parola dopo "."
    if(first_word->next==NULL){
        printf("Il file è vuoto oppure non contiene parole accettate\n");
        exit(0);
    }
    write_csv(first_word,output);
    free_word(first_word);
}



/*
Inizializza il compito 1 multiprocesso creando la linked list e i tre processi
che comunicheranno tramite un pipe creato
*/
void comp1_par(char *input, char *output){
    char point[30]=".";
    Word *first_word=create_first_word(point);
    int pipes[2];
    pipe(pipes);
    pid_t pid;
    if((pid=fork())>0){
        close(pipes[0]);
        read_txt(first_word,input,true,pipes);
    }
    else if(pid==0){
        close(pipes[1]);
        char preword[30];
        char postword[30];
        while(true){
            if(read(pipes[0],preword,30)!=30){
                break;
            }
            read(pipes[0],postword,30);
            newTuple(first_word,preword,postword);
        }

        // controlla che esista almeno una parola dopo "."
        if(first_word->next==NULL){
            printf("Il file è vuoto oppure non contiene parole accettate\n");
            exit(0);
        }
        
        if((pid=fork())>0){
            wait(NULL);
        }
        else if(pid==0){
            write_csv(first_word,output);
            free_word(first_word);
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