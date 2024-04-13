#include "word.h"

typedef struct
{
    char* name;
    int count;
    struct Tuple* next_tuple;
}Tuple;

void newTuple(Word* first_word, char *wordname, char *next_wordname);