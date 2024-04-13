#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "tuple.h"

int main(int argc, char *argv[]){
    printf("n arg:%d\nargv[1]:%s\n",argc,argv[1]);
    char filename[strlen(argv[1])+6];
    strcpy(filename,"input/");
    strcat(filename,argv[1]);


    Word *linked_list=open_txt(filename);

    printf("linked_list:%d\n",linked_list);
    printf("linked_list:%d prossima:%d\n",linked_list,linked_list->next);

    /* char csv_out[strlen(filename)];
    strcpy(csv_out,"csv/");
    strncat(csv_out,argv[1],strlen(argv[1])-4);
    strcat(csv_out,".csv");
    write_csv(csv_out,linked_list); */
}
