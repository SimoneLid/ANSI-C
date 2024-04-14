#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"



int main(int argc, char *argv[]){
    int flags[2];
    control_num_par(argc,argv,flags);
    if(flags[0]==2 && flags[1]==0){
        printf("Eseguo compito 2 non par\n");
        comp2_mono(argc,argv);
    }
    else if(flags[0]==2 && flags[1]==1){
        printf("Eseguo compito 2 par\n");
        comp2_mono(argc,argv);
    }
    else if(flags[1]==1){
        //printf("Eseguendo compito 1 par\n");
        comp1_mono(argc, argv);
    }
    else{
        //printf("Eseguendo compito 1 non par\n");
        comp1_mono(argc, argv);
    }
}


