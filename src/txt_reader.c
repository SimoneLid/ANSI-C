#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"


void open_txt(char *filename){
    FILE *file_in;
    file_in=fopen(filename,"r");
    struct Word* first_word;
    first_word=create_first_word();
    int line;
    char word[30];
    char pre_word[30]=".";
    int id_word=0;
    line=fgetc(file_in);
    while(line!=EOF){
        if(line!=' ' && line!='\n'){
            word[id_word]=(char)line;
            id_word++;
            printf("%s\n",word);
        }
        else{
            newWord(first_word,word);
            memset(pre_word,0,30);
            strcpy(pre_word,word);
            memset(word,0,30);
            printf("%s\n",word);
            id_word=0;
        }
        line=fgetc(file_in);
    }
    word[id_word]='\0';
    newWord(first_word,word);


    struct Word* pointer;
    pointer=first_word;
    while(pointer!=NULL){
        printf("parola:%s\ncount:%d\n\n",pointer->name,pointer->count);
        pointer=pointer->next;
    }
}