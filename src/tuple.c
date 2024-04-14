#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tuple.h"

void newTuple(Word *first_word, char wordname[30], char next_wordname[30]){
    /* 
    La funzione prende in input il puntatore alla prima parola della lista puntata, cerca
    all'interno il nome della parola precedente (sicuramente presente) e nel caso in cui questa sia
    la prima Tupla riferita a quella parola la inserisce in word->first_tuple, sennò scorre
    tutte le tuple presenti per controllare se ce ne sia una con la parola sucessiva, 
    aumentando solo il counter, se non c'è viene inserita alla fine della lista
    */
    
    Word *pointer;
    pointer=search_word(first_word,wordname);// ritorna il puntatore alla parola precedente
    

    Tuple *tuple = (Tuple*) malloc(sizeof(Tuple));
    // controlla se questa è la prima tupla e ci inserisce i valori
    if(pointer->first_tuple==NULL){
        strcpy(tuple->name,next_wordname);
        tuple->count=1;
        tuple->next_tuple=NULL;
        pointer->first_tuple=tuple;
        return;
    }
    

    Tuple *tuple_pointer;
    tuple_pointer=pointer->first_tuple;
    /*
    controlla tutta la lista di Tuple per vedere se esiste già una Tupla
    contenente la parola successiva
    */
    while(tuple_pointer->next_tuple!=NULL && strcmp(tuple_pointer->name,next_wordname)!=0){
        tuple_pointer=(Tuple *)tuple_pointer->next_tuple;
    }
    
    // controlla se si è fermato perchè ha trovato la parola successiva
    if(strcmp(tuple_pointer->name,next_wordname)==0){
            tuple_pointer->count++;
            return;
    }
    
    
    // inserisce i valori nella nuova Tupla alla fine della lista
    strcpy(tuple->name,next_wordname);
    tuple->count=1;
    tuple->next_tuple=NULL;
    tuple_pointer->next_tuple=tuple;
}


void newTuple_perc(Word *first_word, char wordname[30], char next_wordname[30], char perc[30]){
    /* 
    La funzione fa la stessa cosa di newTuple ma prende in input anche una percentuale
    da inserire come valore nella tupla
    */

    //trasforma la probabilità in float
    float perc_f;
    perc_f=atof(perc);



    Word *pointer;
    pointer=search_word(first_word,wordname);// ritorna il puntatore alla parola precedente
    
    pointer->count-=perc_f;

    Tuple *tuple = (Tuple*) malloc(sizeof(Tuple));
    // controlla se questa è la prima tupla e ci inserisce i valori
    if(pointer->first_tuple==NULL){
        strcpy(tuple->name,next_wordname);
        tuple->count=perc_f;
        tuple->next_tuple=NULL;
        pointer->first_tuple=tuple;
        return;
    }
    

    Tuple *tuple_pointer;
    tuple_pointer=pointer->first_tuple;
    /*
    controlla tutta la lista di Tuple per vedere se esiste già una Tupla
    contenente la parola successiva
    */
    while(tuple_pointer->next_tuple!=NULL){
        tuple_pointer=(Tuple *)tuple_pointer->next_tuple;
    }
    
    // inserisce i valori nella nuova Tupla alla fine della lista
    strcpy(tuple->name,next_wordname);
    tuple->count=perc_f;
    tuple->next_tuple=NULL;
    tuple_pointer->next_tuple=tuple;
}