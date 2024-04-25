#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "word.h"


typedef struct
{
    char name[30];
    float count;
    struct Tuple* next_tuple;
    struct Word* self_word;
}Tuple;

void controlTuple(Word *first_word, char preword[30], char word[30],bool par,int pipes[2]);

void newTuple(Word* first_word, char wordname[30], char next_wordname[30]);

void newTuple_perc(Word *first_word, char wordname[30], char next_wordname[30], char perc[30]);