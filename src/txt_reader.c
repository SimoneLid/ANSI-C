#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "tuple.h"


struct Word *open_txt(char *filename){
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
    Infine ritorna il puntatore alla prima parola della lista puntata
    */
    char ch;
    FILE *file_in;
    file_in=fopen(filename,"rb");
    Word *first_word=create_first_word();


    char line;
    char word[30]="";
    char pre_word[30]=".";
    int id_word=0;
    line=fgetc(file_in);
    while(line!=EOF){
        line=lower_uppercase(line);// *1
        if(is_ascii_accepted(line)){// *2
            word[id_word]=line;
            id_word++;
        }
        else if(is_punct_accepted(line)){// *3
            if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                word[0]=line;
                word[1]='\0';
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
            else{
                word[0]=line;
                word[1]='\0';
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
        }
        else if(line==39){// *4
            if(strcmp(word,"")!=0 && strcmp(word,"'")!=0){
                word[id_word]=line;
                newWord(first_word,word);
                newTuple(first_word,pre_word,word);
                memset(pre_word,0,30);
                strcpy(pre_word,word);
                memset(word,0,30);
                id_word=0;
            }
            else{
                word[0]=line;
                id_word++;
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
        line=fgetc(file_in);
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

    // inizio print
    Word *pointer;
    pointer=first_word;
    Tuple *tuple_pointer;

    int i=0;
    while(pointer!=NULL){
        printf("[%s,%d]={",pointer->name,pointer->count);
        tuple_pointer=pointer->first_tuple;
        printf("[%s,%d]",tuple_pointer->name,tuple_pointer->count);
        tuple_pointer=tuple_pointer->next_tuple;
        while(tuple_pointer!=NULL){
            printf(",[%s,%d]",tuple_pointer->name,tuple_pointer->count);
            tuple_pointer=tuple_pointer->next_tuple;
        }
        printf("}\n");
        pointer=pointer->next;
        i++;
    }
    printf("Numero parole distinte:%d\n",i);
    // fine print
    

    printf("first_word:%d prossima:%d\n",first_word,first_word->next);
    return first_word;
}