#include "csv_writer.h"

/* 
Funzione che prende in input un file su cui scrivere e la prima parola
della lista puntata e scorre la lista scrivendo per ogni Word le Tuple
che la seguono nel csv con le relative probabilità
*/
void write_csv(Word *first_word,char *outfile){
    //apre il file di output
    FILE *file_out=fopen(outfile,"w");
    if(file_out==0){
        printf("Errore nell'apertura del file di output!\n");
        exit(0);
    }


    Word *pointer;
    pointer=first_word;
    Tuple *tuple_pointer;

    // esegue fino alla fine della lista di Word
    while(pointer!=NULL){
        fprintf(file_out,"%s",pointer->name);
        tuple_pointer=(Tuple *)pointer->first_tuple;

        // esegue fino alla fine della lista di Tuple
        while(tuple_pointer!=NULL){
            if((int)tuple_pointer->count%(int)pointer->count==0){
                fprintf(file_out,",%s,%d",tuple_pointer->name,1);
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