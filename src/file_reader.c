#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void open_file(char *filename){
    printf("oprendo file:%s\n",filename);
    FILE *file_in;
    file_in=fopen(filename,"r");
    int line;
    char word[30];
    char pre_word[30]=".";
    int id_word=0;
    line=fgetc(file_in);
    while(line!=EOF){
        if(line!=' ' && line!='\n'){
            word[id_word]=(char)line;
            id_word++;
        }
        else{
            word[id_word]='\0';
            printf("word attuale:%s\nword precedente:%s\n\n\n",word,pre_word);
            strcpy(pre_word,word);
            pre_word[id_word]='\0';
            id_word=0;
        }
        line=fgetc(file_in);
    }
    word[id_word]='\0';
    printf("word attuale:%s\nword precedente:%s\n\n\n",word,pre_word);

}