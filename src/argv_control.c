#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"

int control_argv(int argc, char **argv, int *flags){
    //printf("n arg:%d\n",argc);
    if(strlen(argv)<4){
        printf("Non ci sono abbastanza argomenti\n");
    }
    flags[0]=number_control(argv[1]);
    flags[1]=par_control(argv[2]);
    //printf("compito:%d\npar:%d\n",flags[0],flags[1]);
    return flags;
}

int number_control(char *flag_number){
    if(strcmp(flag_number,"-1")==0){
        return 1;
    }
    else if(strcmp(flag_number,"-2")==0){
        return 2;
    }
    else{
        printf("Scegliere se eseguire il compito 1 o il compito 2 tramite -1/-2\n");
        exit(0);
    }
}

int par_control(char *flag_par){
    if(strcmp(flag_par,"-p")==0){
        return 1;
    }
    else{
        return 0;
    }
}