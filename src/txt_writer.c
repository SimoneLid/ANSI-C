#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tuple.h"

Word *random_start_word(Word *first_word){
    /* 
    Funzione che controlla se ci sono le parole ".","!" e "?" e in base a quante ce ne sono
    tra le parole del csv randomizza una di quelle presenti e scrive una parola a caso
    tra le successive di quella scelta
    */

    // crea un seed per non avere gli stessi numeri random
    srand(time(NULL));

    char quest_str[30];
    char escl_str[30];
    quest_str[0]='?';
    escl_str[0]='!';

    // controlla quali punteggiature sono presenti nel csv e salva i puntatori
    Word *point=first_word;
    Word *question=search_word(first_word,quest_str);
    Word *esclamation=search_word(first_word,escl_str);
    Tuple *start_point;


    /*
    controlla quali puntatori esistono (cioè la parola è nel csv) e randomizza la punteggiatura
    da cui iniziare
    */
    float sum;
    if(question!=NULL && esclamation!=NULL){
        int num=rand()%3;
        if(num==0){
            sum=point->count;
            start_point=(Tuple *)point->first_tuple;
        }
        else if(num==1){
            sum=question->count;
            start_point=(Tuple *)question->first_tuple;
        }
        else{
            sum=esclamation->count;
            start_point=(Tuple *)esclamation->first_tuple;
        }
    }
    else if(question!=NULL){
        int num=rand()%2;
        if(num==0){
            sum=point->count;
            start_point=(Tuple *)point->first_tuple;
        }
        else{
            sum=question->count;
            start_point=(Tuple *)question->first_tuple;
        }
    }
    else if(esclamation!=NULL){
        int num=rand()%2;
        if(num==0){
            sum=point->count;
            start_point=(Tuple *)point->first_tuple;
        }
        else{
            sum=esclamation->count;
            start_point=(Tuple *)esclamation->first_tuple;
        }
    }
    else{
        sum=point->count;
        start_point=(Tuple *)point->first_tuple;
    }


    // randomizza una tra le tuple collegate alla punteggiatura selezionata casualmente
    double num_r =((float)rand()/(float)(RAND_MAX)) * sum;
    while(num_r-start_point->count>0){
        num_r-=start_point->count;
        start_point=(Tuple *)start_point->next_tuple;
    }
    

    return search_word(first_word,start_point->name);
}


void write_random_text(Word *first_word, char *outfile, int n_word, char start_word[30], bool exist_start_word){
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
    
    // se è stata data la prima parola da riga di comando vede se c'è nel csv
    Word *start;
    if(exist_start_word){
        start=search_word(first_word,start_word);
        if(start==NULL){
            exist_start_word=false;
        }
    }


    // se non è stata data una prima parola la randomizza
    if(!exist_start_word){
        start=random_start_word(first_word);
        printf("Parola iniziale non inserita o non presente!\nTesto creato partendo dalla parola random: %s\n",start->name);
    }

    
    // scrive per numword volte una parola e poi randomizza la successiva tra le Tuple collegate
    Tuple *tuple_pointer;
    char upper[30];
    double num_r;
    char last_written[30]=".";
    while(n_word>0){
        if(strcmp(last_written,".")==0 || strcmp(last_written,"!")==0 || strcmp(last_written,"?")==0){
            strcpy(upper,start->name);
            if(upper[0]==-61){
                upper[1]=upper_lowercase(upper[1]);
            }
            else{
                upper[0]=upper_lowercase(upper[0]);
            }
            fprintf(file_out,"%s ",upper);
        }
        else{
            fprintf(file_out,"%s ",start->name);
        }
        strcpy(last_written,start->name);
        num_r =((float)rand()/(float)(RAND_MAX)) * start->count;
        tuple_pointer=(Tuple *)start->first_tuple;
        while(num_r-(double)tuple_pointer->count>0){
            num_r=num_r-(double)tuple_pointer->count;
            tuple_pointer=(Tuple *)tuple_pointer->next_tuple;
        }
        start=tuple_pointer->self_word;
        n_word--;
    }



    
}


