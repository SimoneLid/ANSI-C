#include "csv_reader.h"

/* 
La funzione prende in input il nome del file csv e lo apre
Dopo legge ogni carattere del testo e controlla diverse cose:
    *1: controlla se il carattere non termina una parola o una percentuale e in 
        base a dei valori booleani lo inserisce nella parola che inizia una riga,
        in una parola successiva o in una percentual
    *2: controlla se è una "," e salva la parola o il numero appena terminati
    *3: controlla se è uno "\n", salvando l'ultima parola e resettando la parola
        che inizia la riga
*/
void read_csv(Word *first_word,char *filename,bool par, int pipes[2]){
    // apre e controlla che il file esista
    FILE *file_in=fopen(filename,"r");
    if(file_in==0){
        printf("Il file di input non esiste!\n");
        exit(0);
    }



    bool is_num=false;
    bool pre_word_found=false;
    char ch;
    char word[30]="";
    char pre_word[30]="";
    char num[30]="";
    int id_word=0;
    ch=fgetc(file_in);
    while(ch!=EOF){
        if(ch!=','&& ch!='\n'){// *1
            if(!pre_word_found){
                pre_word[id_word]=ch;
            }
            else if(!is_num){
                word[id_word]=ch;
            }
            else{
                num[id_word]=ch;
            }
            id_word++;
        }
        else if(ch==','){// *2
            if(!pre_word_found){
                pre_word_found=true;
                id_word=0;
            }
            else if(!is_num){
                is_num=true;
                id_word=0;
            }
            else{
                is_num=false;
                id_word=0;
                controlTuple_perc(first_word,pre_word,word,num,par,pipes);
                memset(word,'\0',30);
                memset(num,'\0',30);
            }
        }
        else if(ch=='\n'){// *3
            pre_word_found=false;
            is_num=false;
            controlTuple_perc(first_word,pre_word,word,num,par,pipes);
            memset(pre_word,'\0',30);
            memset(word,'\0',30);
            memset(num,'\0',30);
            id_word=0;
        }
        ch=fgetc(file_in);
    }


    if(par){
        close(pipes[1]);
        wait(NULL);
    }
}