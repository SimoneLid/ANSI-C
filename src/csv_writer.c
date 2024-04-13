#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "tuple.h"

void write_csv(char *outfile, Word *first_word){
    /* 
    Funzione che prende in input un file su cui scrivere e la prima parola
    della lista puntata e scrive il csv con le relative probabilità
    */
    FILE *file_out=fopen(outfile,"w");


    Word *pointer;
    pointer=first_word;
    Tuple *tuple_pointer;

    // esegue fino alla fine della lista di Word
    while(pointer!=NULL){
        fprintf(file_out,"%s",pointer->name);
        tuple_pointer=pointer->first_tuple;
        if(tuple_pointer->count%pointer->count==0){
            fprintf(file_out,",%s,%d",tuple_pointer->name,(tuple_pointer->count/pointer->count));
        }
        else{
            fprintf(file_out,",%s,%.4f",tuple_pointer->name,((float)tuple_pointer->count/pointer->count));
        }
        tuple_pointer=tuple_pointer->next_tuple;
        while(tuple_pointer!=NULL){// esegue fino alla fine della lista di Tuple
            if(tuple_pointer->count%pointer->count==0){
                fprintf(file_out,",%s,%d",tuple_pointer->name,(tuple_pointer->count/pointer->count));
            }
            else{
                fprintf(file_out,",%s,%.4f",tuple_pointer->name,((float)tuple_pointer->count/pointer->count));
            }
            tuple_pointer=tuple_pointer->next_tuple;
        }
        fprintf(file_out,"\n");
        pointer=pointer->next;
    }
}