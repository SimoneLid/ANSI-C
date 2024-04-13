typedef struct
{
    char* name;
    int count;
    struct Word* next;
    struct Tuple* first_tuple;
}Word;

Word* create_first_word();

void newWord(Word* first_word, char *wordname);

Word* search_word(Word* first_word, char *wordname);