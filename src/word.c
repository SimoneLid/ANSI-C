#include "word.h"


// Funzione che crea la prima Word della lista puntata e ritorna il puntatore
Word *create_first_word(char word[30]){
    Word *first_word = (Word*) calloc(1,sizeof(Word));
    if(first_word==NULL){
        printf("Errore nell'allocazione di memoria!\n");
        exit(1);
    }
    strcpy(first_word->name,word);
    first_word->count=0;
    first_word->next=NULL;
    first_word->first_tuple=NULL;
    return first_word;
}


/* 
Dato in input il puntatore alla prima parola della lista, ritorna
il puntatore alla Word contnente la parola cercata
*/
Word *search_word(Word *first_word, char wordname[30]){
    Word *pointer;
    pointer=first_word;

    // arriva fino all'elemento cercato
    while(pointer!=NULL && strcmp(pointer->name,wordname)!=0){
        pointer=(Word *)pointer->next;
    }
    return pointer;
}