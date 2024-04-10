#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Tuple
{
    char* word_actual;
    char* word_next;
    int count;
    struct Tuple* next_tuple;
};

struct WordCount
{
    char* word;
    int count;
    struct WordCount* next_count;
};

int main(){
    struct Tuple* coppia;
    coppia = (struct Tuple*) calloc(1, sizeof(struct Tuple));
    coppia->word_actual="ciao";
    coppia->word_next="domani";
    coppia->count=1;
    struct Tuple* coppia2;
    coppia2 = (struct Tuple*) calloc(1, sizeof(struct Tuple));
    coppia2->word_actual="domani";
    coppia2->word_next="andiamo";
    coppia2->count=1;
    coppia->next_tuple=coppia2;
    printf("parola:%s\nparola dopo:%s\ncount:%d\n",coppia->word_actual,coppia->word_next,coppia->count);
    printf("puntatore dopo:%s\n",coppia->next_tuple->word_actual);

}