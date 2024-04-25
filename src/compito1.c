#include "compito1.h"


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
}


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
    else{
        close(pipes[1]);
        char preword[30];
        char postword[30];
        while(true){
            if(read(pipes[0],preword,30)==0){
                break;
            }
            read(pipes[0],postword,30);
            printf("Letto:%s,%s\n",preword,postword);
            newTuple(first_word,preword,postword);
        }

        // controlla che esista almeno una parola dopo "."
        if(first_word->next==NULL){
            printf("Il file è vuoto oppure non contiene parole accettate\n");
            exit(0);
        }
        
        if((pid=fork())>0){
            wait();
        }
        else{
            write_csv(first_word,output);
        }
    }
}