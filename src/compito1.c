#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"

void comp1_mono(char *argv[]){
    char point[30];
    point[0]='.';
    Word *first_word;
    first_word=create_first_word(point);
    read_txt(first_word,argv[2]);
    write_csv(first_word,argv[3]);
}