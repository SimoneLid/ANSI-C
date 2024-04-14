#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"

int *control_num_par(int argc, char **argv, int *flags){
    /*
    Controlla se gli argomenti sono almeno 4 (cioè il minimo per il compito 1 monoprocesso)
    poi controlla le flag del numero del compito e parallelo
    */
    if(argc<4){
        printf("Non ci sono abbastanza argomenti\n");
        exit(0);
    }
    flags[0]=number_control(argv[1]);// controlla il numero del compito
    flags[1]=par_control(argv[2]);// controlla se c'è la flag -p
    return flags;
}


int number_control(char *flag_number){
    // controlla la flag del numero
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
    // controlla la flag del parallelo
    if(strcmp(flag_par,"-p")==0){
        return 1;
    }
    else{
        return 0;
    }
}


void num_word_control(char *num_word){
    /*
    controlla (nel caso del compito 2) se il numero delle parole inserite
    è un intero consentito
    */
    int n_word=atoi(num_word);
    if(n_word<=0){
        printf("Numero di parole non valido o non inserito\n");
        exit(0);
    }
}


bool argv_comp2_mono(int argc,char **argv){
    /*
    Controlla se ci sono abbastanza argomenti per eseguire il compito 2 monoprocesso
    e poi controlla se è stata inserita la parola iniziale
    */
    if(argc<5){
        printf("Non ci sono abbastanza argomenti\n");
        exit(0);
    }
    num_word_control(argv[4]);
    if(argc>=6){
        return true;
    }
    return false;
}


