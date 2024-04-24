#include "csv_writer.h"


void write_csv(Word *first_word,char *outfile){
    /* 
    Funzione che prende in input un file su cui scrivere e la prima parola
    della lista puntata e scrive il csv con le relative probabilità
    */
    FILE *file_out=fopen(outfile,"w");
    if(file_out==0){
        printf("Il file di output non esiste!\n");
        exit(0);
    }

    

    Word *pointer;
    pointer=first_word;
    Tuple *tuple_pointer;

    // esegue fino alla fine della lista di Word
    while(pointer!=NULL){
        fprintf(file_out,"%s",pointer->name);
        tuple_pointer=(Tuple *)pointer->first_tuple;
        if((int)tuple_pointer->count%(int)pointer->count==0){
            fprintf(file_out,",%s,%d",tuple_pointer->name,(int)(tuple_pointer->count/pointer->count));
        }
        else{
            fprintf(file_out,",%s,%f",tuple_pointer->name,(tuple_pointer->count/pointer->count));
        }
        tuple_pointer=(Tuple *)tuple_pointer->next_tuple;
        while(tuple_pointer!=NULL){// esegue fino alla fine della lista di Tuple
            if((int)tuple_pointer->count%(int)pointer->count==0){
                fprintf(file_out,",%s,%d",tuple_pointer->name,(int)(tuple_pointer->count/pointer->count));
            }
            else{
                fprintf(file_out,",%s,%f",tuple_pointer->name,(tuple_pointer->count/pointer->count));
            }
            tuple_pointer=(Tuple *)tuple_pointer->next_tuple;
        }
        fprintf(file_out,"\n");
        pointer=(Word *)pointer->next;
    }
}