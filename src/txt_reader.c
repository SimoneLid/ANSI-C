#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "tuple.h"


void read_txt(Word *first_word,char *filename){
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
        *5.gli unici caratteri rimasti sono le punteggiature da eliminare quindi
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
    


    char ch;
    char word[30]="";
    char pre_word[30]=".";
    int id_word=0;
    ch=fgetc(file_in);
    while(ch!=EOF){
        
        ch=lower_uppercase(ch);// *1
        if(is_ascii_accepted(ch)){// *2
            word[id_word]=ch;
            id_word++;
        }
        else if(is_punct_accepted(ch)){// *3
            if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                word[0]=ch;
                word[1]='\0';
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
            else{
                word[0]=ch;
                word[1]='\0';
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
        }
        else if(ch==39){// *4
            if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
                word[id_word]=ch;
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
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
        else if(strcmp(word,"")!=0){// *5
            if(strcmp(word,"'")==0){
                memset(word,0,30);
                id_word=0;
            }
            else{
            newWord(first_word,word);
            newTuple(first_word,pre_word,word);
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
        newWord(first_word,word);
        newTuple(first_word,pre_word,word);
        Word *tmp=(Word *)first_word->next;
        newTuple(first_word,word,tmp->name);
    }
    else{
        if(strcmp(pre_word,".")!=0){
            Word* tmp=(Word *)first_word->next;
            newTuple(first_word,pre_word,tmp->name);
        }
        else{
            first_word->count--;
        }
    }
    fclose(file_in);

    // controlla che esista almeno una parola dopo "."
    if(first_word->next==NULL){
        printf("Il file è vuoto oppure non contiene parole accettate\n");
        exit(0);
    }
}