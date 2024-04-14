#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"

void comp2_mono(int argc, char **argv){
    // inizializza il compito 2 monoprocesso
    bool exist_start_word=argv_comp2_mono(argc,argv);
    char empty[30];
    empty[0]='\0';
    Word *first_word = create_first_word(empty);
    read_csv(first_word,argv[2]);
    int n_word=atoi(argv[4]);
    if(exist_start_word){
        write_random_text(first_word,argv[3],n_word,argv[5],exist_start_word);
    }
    else{
        write_random_text(first_word,argv[3],n_word,"--",exist_start_word);
    }
}