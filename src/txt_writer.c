#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "tuple.h"

Word *random_start_word(Word *first_word){
    /* 
    Funzione che controlla se ci sono le parole ".","!" e "?" e in base a quante ne esistono
    tra le parole del csv randomizza una di quelle esistenti e scrive una parola a caso
    tra le successive di quella scelta
    */
    

    Word *point=search_word(first_word,".");
    Word *question=search_word(first_word,"?");
    Word *esclamation=search_word(first_word,"!");
    Word *array[3]={point,question,esclamation};
    int i=2;
    int num;
    do{
        num = (rand() % (i + 1));
        i--;
    }while(array[num]==NULL);

    Tuple *start_point=array[num]->first_tuple;
    double num_r =(double)rand() / (double)((unsigned)RAND_MAX + 1);
    while(num_r-start_point->count>0){
        num_r-=start_point->count;
        start_point=start_point->next_tuple;
    }
    return search_word(first_word,start_point->name);
}


void write_random_text(Word *first_word, char *outfile, int numword, char start_word[30], bool exist_start_word){
    /* 
    Funzione che prende in input un file su cui scrivere, la prima parola
    della lista puntata, il numero di parole da scrivere e la possibile prima parola
    e scrive il testo random sul file txt
    */

    
    FILE *file_out=fopen(outfile,"w");
    if(file_out==0){
        printf("Impossibile aprire il file di output\n");
        exit(0);
    }

    
    if(exist_start_word){
        Word *tmp;
        tmp=search_word(first_word,start_word);
        if(tmp==NULL){
            exist_start_word=false;
        }
    }
    
    if(!exist_start_word){
        Word *start=random_start_word(first_word);
        printf("Parola iniziale non inserita o non presente!\nTesto creato partendo dalla parola random:%s\n",start);
    }


    Word *pointer;
    pointer=first_word;
    Tuple *tuple_pointer;



    
}


