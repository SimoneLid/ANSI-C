#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
	 
#include <stdlib.h>   // Declaration for exit()
	 
int globalVariable = 2;
	 
int main()
{
    int pipe_info[2];
    char buffer[100];
    pid_t pid;
    if(pipe(pipe_info)==-1){
        printf("Fra crushato");
        exit(0);
    }
    if((pid=fork())>0){
        close(pipe_info[1]);
        memset(buffer,'\0',100);
        int i=0;
        while(true){
            if(read(pipe_info[0],buffer,30)==0){
                exit(0);
            }
            printf("Letto %s: %d\n",buffer,i);
            i++;
        }
    }
    else{
        int i=0;
        while(i<20){
            char word[30]="prova";
            write(pipe_info[1],word,30);
            i++;
        }
        close(pipe_info[1]);
    }
}
