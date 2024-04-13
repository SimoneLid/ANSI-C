typedef struct
{
    char name[30];
    int count;
    struct Word* next;
    struct Tuple* first_tuple;
}Word;

Word* create_first_word();

void newWord(Word* first_word, char wordname[30]);

Word* search_word(Word* first_word, char wordname[30]);