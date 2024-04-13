#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "tuple.h"


void open_txt(char *filename, char *csv_out){
    /* 
    La funzione prende in input il nome del file e lo apre, creando la prima parola, cioè "."
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
    Word *first_word;
    first_word=create_first_word();
    FILE *file_in=fopen(filename,"r");
    


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
    if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
        newWord(first_word,word);
        newTuple(first_word,pre_word,word);
        if(strcmp(word,".")!=0){
            newTuple(first_word,word,first_word->next);
        }
    }
    else{
        if(strcmp(pre_word,".")!=0){
            Word* pointer=first_word->next;
            newTuple(first_word,pre_word,pointer->name);
        }
    }
    fclose(file_in);

    // controlla che esista almeno una parola dopo "."
    if(first_word->next==NULL){
        printf("Errore!!\nIl file è vuoto oppure non contiene parole accettate\n");
        exit(0);
    }
    
    
    write_csv(csv_out,first_word);


    //inizio print
    /* Word *pointer;
    pointer=first_word;
    Tuple *tuple_pointer;

    while(pointer!=NULL){
        printf("[%s,%d]={",pointer->name,pointer->count);
        tuple_pointer=pointer->first_tuple;
        printf("[%s,%.4f]",tuple_pointer->name,((float)tuple_pointer->count/pointer->count));
        tuple_pointer=tuple_pointer->next_tuple;
        while(tuple_pointer!=NULL){
            printf(",[%s,%.4f]",tuple_pointer->name,((float)tuple_pointer->count/pointer->count));
            tuple_pointer=tuple_pointer->next_tuple;
        }
        printf("}\n");
        pointer=pointer->next;
    } */    
}