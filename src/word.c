#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "word.h"

Word *create_first_word(){
    /* 
    Funzione che crea la prima Word della lista puntata (contenente la parola ".")
    e ritorna il puntatore
    */
    Word *first_word = (Word*) malloc(sizeof(Word));
    strcpy(first_word->name,".");
    first_word->count=1;
    first_word->next=NULL;
    return first_word;
}

void newWord(Word *first_word, char wordname[30]){
    /*
    La funzione prende il puntatore all'inizio della lista puntata e il nome della parola 
    da inserire. Controlla se una Word con quel nome esiste già, nel caso aumenta solo il counter,
    sennò scorre fino alla fine della lista e aggiunge una nuova struttura Word
    che viene collegata come successiva dell'ultima
    */
    Word *pointer;
    pointer=first_word;

    /*
    controlla tutta la lista di Word per vedere se esiste già una Word
    contenente la parola
    */
    while(pointer->next!=NULL && strcmp(pointer->name,wordname)!=0){
        pointer=pointer->next;
    }

    // controlla se si è fermato perchè ha trovato la parola
    if(strcmp(pointer->name,wordname)==0){
            pointer->count++;
            return;
    }

    // crea e alloca la nuova Word, ci inserisce i valori e la inserisce alla fine della lista
    Word *word = (Word*) malloc(sizeof(Word));
    strcpy(word->name,wordname);
    word->count=1;
    word->next=NULL;
    pointer->next=word;
}


Word *search_word(Word *first_word, char wordname[30]){
    /* 
    Dato in input il puntatore alla prima parola della lista, ritorna
    il puntatore alla Word contnente la parola cercata
    */
    Word *pointer;
    pointer=first_word;

    // arriva fino all'elemento cercato
    while(strcmp(pointer->name,wordname)!=0){
        pointer=pointer->next;
    }
    return pointer;
}