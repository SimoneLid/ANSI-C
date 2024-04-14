#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "tuple.h"

void read_csv(Word *first_word,char *filename){
    /* 
    La funzione prende in input il nome del file txt e lo apre
    Dopo legge ogni carattere del testo e controlla diverse cose:
        *1.
    */


    // apre e controlla che il file esista
    FILE *file_in=fopen(filename,"r");
    if(file_in==0){
        printf("Il file di input non esiste!\n");
        exit(0);
    }



    bool is_first_word=true;
    bool is_num=false;
    bool pre_word_found=false;
    char ch;
    char word[30]="";
    char pre_word[30]="";
    char num[30]="";
    int id_word=0;
    ch=fgetc(file_in);
    while(ch!=EOF){
        if(ch!=','&& ch!='\n'){
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
        else if(ch==','){
            if(!pre_word_found){
                pre_word_found=true;
                if(is_first_word){
                    first_word=create_first_word(pre_word);
                    is_first_word=false;
                }
                else{
                    newWord(first_word,pre_word);
                }
                id_word=0;
            }
            else if(!is_num){
                is_num=true;
                id_word=0;
            }
            else{
                is_num=false;
                id_word=0;
                newTuple_perc(first_word,pre_word,word,num);
                memset(word,'\0',30);
                memset(num,'\0',30);
            }
        }
        else if(ch=='\n'){
            pre_word_found=false;
            is_num=false;
            newTuple_perc(first_word,pre_word,word,num);
            memset(pre_word,'\0',30);
            memset(word,'\0',30);
            memset(num,'\0',30);
            id_word=0;
        }
        ch=fgetc(file_in);
    }

    //inizio print
    Word *pointer;
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
    }
}