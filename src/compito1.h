#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "txt_reader.h"


void comp1_mono(char *input, char *output);

void comp1_par(char *input, char *output);