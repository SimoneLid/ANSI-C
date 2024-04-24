#include "word.h"


Word *create_first_word(char word[30]){
    /* 
    Funzione che crea la prima Word della lista puntata e ritorna il puntatore
    */
    Word *first_word = (Word*) malloc(sizeof(Word));
    strcpy(first_word->name,word);
    first_word->count=0;
    first_word->next=NULL;
    first_word->first_tuple=NULL;
    return first_word;
}


Word *search_word(Word *first_word, char wordname[30]){
    /* 
    Dato in input il puntatore alla prima parola della lista, ritorna
    il puntatore alla Word contnente la parola cercata
    */
    Word *pointer;
    pointer=first_word;

    // arriva fino all'elemento cercato
    while(pointer!=NULL && strcmp(pointer->name,wordname)!=0){
        pointer=(Word *)pointer->next;
    }
    return pointer;
}