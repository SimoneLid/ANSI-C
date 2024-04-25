#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <bits/getopt_core.h>

#include "compito2.h"


int main(int argc, char *argv[]){
    int c;
    int comp_flag=0;
    bool par=false;
    char *input=NULL;
    char *output=NULL;
    int n_word=0;
    char *start_word=NULL;

    //controlla tutti gli input da linea di comando
    while ((c = getopt (argc, argv, "12pi:o:n:s:")) != -1)
    switch (c)
    {
    case '1':
        if(comp_flag==2){
            printf("Impossibile eseguire entrambi i compiti\n");
            exit(1);
        }
        comp_flag = 1;
        break;
    case '2':
        if(comp_flag==1){
            printf("Impossibile eseguire entrambi i compiti\n");
            exit(1);
        }
        comp_flag = 2;
        break;
    case 'p':
        par=true;
        break;
    case 'i':
        input=optarg;
        break;
    case 'o':
        output=optarg;
        break;
    case 'n':
        n_word=atoi(optarg);
        break;
    case 's':
        strcpy(start_word,optarg);
        break;
    }


    if(comp_flag==0){
        printf("Obbligatorio specificare un compito da eseguire\n");
        exit(1);
    }
    if(input==NULL || output==NULL){
        printf("Obbligatorio specificare un file in input e un file in output\n");
        exit(1);
    }

    // print delle informazioni sull'esecuzione
    printf("Compito:%d\nParallelo:%s\n",comp_flag,par ? "true" : "false");
    printf("File input:%s\nFile output:%s\n",input,output);

    // in base alle flag decide il compito da eseguire
    if(comp_flag==2 && par){
        comp2_par(input,output,n_word,start_word);
    }
    else if(comp_flag==2 && !par){
        comp2_mono(input,output,n_word,start_word);
    }
    else if(comp_flag==1 && par){
        comp1_par(input,output);
    }
    else{
        comp1_mono(input,output);
    }
}


