#include "compito2.h"


void comp2_mono(char *input, char *output, int n_word, char start_word[30]){
    char punct[30]=".";
    Word *first_word = create_first_word(punct);
    read_csv(first_word,input);
    write_random_text(first_word,output,n_word,start_word);
}