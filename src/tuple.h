#include "word.h"

typedef struct
{
    char name[30];
    float count;
    struct Tuple* next_tuple;
}Tuple;

void newTuple(Word* first_word, char wordname[30], char next_wordname[30]);

void newTuple_perc(Word *first_word, char wordname[30], char next_wordname[30], char perc[30]);