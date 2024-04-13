#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"



int main(int argc, char *argv[]){
    int flags[2];
    control_argv(argc,argv,flags);
    if(flags[0]==2){
        printf("Compito 2 non ancora implementato!\n");
        exit(0);
    }
    if(flags[1]==1){
        //printf("Eseguendo compito 1 par\n");
        open_txt(argv[3],argv[4]);
    }
    else{
        //printf("Eseguendo compito 1 non par\n");
        open_txt(argv[2],argv[3]);
    }
}


