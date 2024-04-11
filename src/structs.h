#include <stdlib.h>
#include <string.h>

struct Tuple
{
    char* name;
    int count;
    struct Tuple* next_tuple;
};

struct Word
{
    char* name;
    int count;
    struct Word* next;
    struct Tuple* tuple;
};

struct Word* create_first_word(){
    struct Word* first_word;
    first_word = (struct Word*) calloc(1, sizeof(struct Word));
    first_word->name=".";
    first_word->count=1;
    return first_word;
}

void newWord(struct Word* first_word, char *wordname){
    /*
    La funzione prende il puntatore all'inizio della lista puntata e il nuovo nome della parola 
    da inserire. Controlla se una Word con quel nome esiste già, nel caso aumenta solo il counter,
    sennò scorre fino alla fine della lista e aggiunge una nuova struttura Word
    che viene collegata come successiva dell'ultima
    */
    struct Word* pointer;
    pointer=first_word;
    while(pointer->next!=NULL){//arriva fino al'ultimo elemento
        if(strcmp(pointer->name,wordname)==0){
            pointer->count++;
            return;
        }
        pointer=pointer->next;
    }
    struct Word* word = (struct Word*) calloc(1, sizeof(struct Word));//crea e alloca la nuova Word
    char *new_name = (char *)malloc(strlen(wordname)+1);//crea e alloca la stringa del nome
    strcpy(new_name,wordname);//IMPORTANTISSIMO
    word->name=new_name;
    word->count=1;
    pointer->next=word;
}