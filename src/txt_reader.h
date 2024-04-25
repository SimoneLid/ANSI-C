#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "csv_writer.h"
#include "ascii_control.h"


void read_txt(Word *first_word,char *filename,bool par,int pipes[2]);