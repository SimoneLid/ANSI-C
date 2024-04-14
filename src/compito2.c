#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"

void comp2_mono(int argc, char **argv){
    bool exist_start_word=argv_comp2_mono(argc,argv);
    Word *first_word;
    read_csv(first_word,argv[2]);
    if(exist_start_word){
    write_random_text(first_word,argv[3],argv[4],argv[5],exist_start_word);
    }
    else{
        write_random_text(first_word,argv[3],argv[4],"--",exist_start_word);
    }
}