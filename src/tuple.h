#include "word.h"

typedef struct
{
    char name[30];
    int count;
    struct Tuple* next_tuple;
}Tuple;

void newTuple(Word* first_word, char wordname[30], char next_wordname[30]);