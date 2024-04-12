#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
    printf("n arg:%d\nargv[1]:%s\n",argc,argv[1]);
    char *filename;
    filename = argv[1];
    open_txt(filename);
}
