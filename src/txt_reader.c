#include "txt_reader.h"


void read_txt(Word *first_word,char *filename,bool par,int pipes[2]){
    /* 
    La funzione prende in input il nome del file txt e lo apre
    Dopo legge ogni carattere del testo e controlla diverse cose:
        *1.controlla se è una lettera maiuscola e in caso la fa diventare minuscola
        *2.controlla se il carattere è un carattere accettato nelle parole e lo inserisce
            nella parola corrente
        *3.controlla se il carattere è una punteggiatura che termina una frase e 
            salva (se non è vuota o solo "'") la parola precedente (ora terminata) e la
            punteggiatura come parola separata.
        *4.controlla se il carattere è un "'" e nel caso la parola prima non sia vuota 
            (o composta solo da "'") loattacca alla parola precedente,
            sennò diventa il primo carattere della parola successiva
        *5.controlla se il carattere è a due byte (ch=-61) e controlla poi il secondo byte per
            vedere se è un carattere accettato
        *6.gli unici caratteri rimasti sono le punteggiature da eliminare quindi
            viene salvata (sempre se non è vuota o solo "'") la parola appena terminata
    Alla fine del while viene salvata anche l'ultima parola (sempre se non è vuota o solo "'")
    Poi chiama la funzione che scrive il file csv
    */


    // apre e controlla che il file esista
    FILE *file_in=fopen(filename,"r");
    if(file_in==0){
        printf("Il file di input non esiste!\n");
        exit(0);
    }
    
    
    bool is_first_word=true;
    char prima_word[30];
    char b2;
    char ch;
    char word[30]="";
    char pre_word[30]=".";
    int id_word=0;
    ch=fgetc(file_in);
    while(ch!=EOF){
        //printf("ch:%d\n",ch);
        ch=lower_uppercase(ch);// *1
        if(is_ascii_accepted(ch)){// *2
            word[id_word]=ch;
            id_word++;
        }
        else if(is_punct_accepted(ch)){// *3
            if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
                controlTuple(first_word,pre_word,word,par,pipes);
                if(is_first_word){
                    strcpy(prima_word,word);
                    is_first_word=false;
                }
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                word[0]=ch;
                word[1]='\0';
                controlTuple(first_word,pre_word,word,par,pipes);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
            else{
                word[0]=ch;
                word[1]='\0';
                controlTuple(first_word,pre_word,word,par,pipes);
                if(is_first_word){
                    strcpy(prima_word,word);
                    is_first_word=false;
                }
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
        }
        else if(ch==39){// *4
            if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
                word[id_word]=ch;
                controlTuple(first_word,pre_word,word,par,pipes);
                if(is_first_word){
                    strcpy(prima_word,word);
                    is_first_word=false;
                }
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
            else{
                word[0]=ch;
                id_word=1;
            }
        }
        else if(ch==-61){// *5
            b2=fgetc(file_in);
            if(is_ascii_accepted_2b(b2)){
                b2=lower_uppercase(b2);
                word[id_word]=ch;
                word[id_word+1]=b2;
                id_word+=2;
            }
            else{
                if(strcmp(word,"")!=0){
                    if(strcmp(word,"'")==0){
                        memset(word,0,30);
                        id_word=0;
                    }
                    else{
                        controlTuple(first_word,pre_word,word,par,pipes);
                        if(is_first_word){
                            strcpy(prima_word,word);
                            is_first_word=false;
                        }
                        memset(pre_word,0,30);
                        strcpy(pre_word,word);
                        memset(word,0,30);
                        id_word=0;
                    }
                }
            }
        }
        else if(strcmp(word,"")!=0){// *6
            if(strcmp(word,"'")==0){
                memset(word,0,30);
                id_word=0;
            }
            else{
                controlTuple(first_word,pre_word,word,par,pipes);
                if(is_first_word){
                    strcpy(prima_word,word);
                    is_first_word=false;
                }
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
        }
        ch=fgetc(file_in);
    }

    /*
    alla fine controlla se l'ultima parola controllata è una parola accettata e
    la inserisce nella lista escludendo il punto
    */
    if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
        controlTuple(first_word,pre_word,word,par,pipes);
        if(is_first_word){
            strcpy(prima_word,word);
            is_first_word=false;
        }
        controlTuple(first_word,word,prima_word,par,pipes);
    }
    else{
        if(strcmp(pre_word,".")!=0){
            controlTuple(first_word,pre_word,prima_word,par,pipes);
        }
    }
    fclose(file_in);


    if(par){
        close(pipes[1]);
        wait(NULL);
    }

    //inizio print
    /* Word *pointer;
    pointer=first_word;
    Tuple *tuple_pointer;

    while(pointer!=NULL){
        printf("[%s,%.4f]={",pointer->name,pointer->count);
        tuple_pointer=pointer->first_tuple;
        printf("[%s,%.4f]",tuple_pointer->name,tuple_pointer->count);
        tuple_pointer=tuple_pointer->next_tuple;
        while(tuple_pointer!=NULL){
            printf(",[%s,%.4f]",tuple_pointer->name,tuple_pointer->count);
            tuple_pointer=tuple_pointer->next_tuple;
        }
        printf("}\n");
        pointer=pointer->next;
    } */
}