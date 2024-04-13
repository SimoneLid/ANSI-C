#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "tuple.h"

void write_csv(char *filename, Word* linked_list){
    printf("inizio scrittura\n");
    FILE *file_out;
    file_out=fopen(filename,"w");

    /* struct Tuple* tuple;
    tuple=linked_list->first_tuple; */
    printf("%s",linked_list->name);
    /* while(linked_list!=NULL){
        fprintf(file_out,linked_list->name);
        while(tuple!=NULL){
            fprintf(file_out,tuple->name);
            fprintf(file_out,",");
            fprintf(file_out,tuple->count);
            tuple=tuple->next_tuple;
        }
        fprintf(file_out,"\n");
        linked_list=linked_list->next;
        tuple=linked_list->first_tuple;
    }
    fclose(file_out); */
}