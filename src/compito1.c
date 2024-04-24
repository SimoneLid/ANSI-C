#include "compito1.h"


void comp1_mono(char *input, char *output){
    char point[30]=".";
    Word *first_word=create_first_word(point);
    read_txt(first_word,input);
    write_csv(first_word,output);
}