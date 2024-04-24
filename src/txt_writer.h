#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "compito1.h"


Word *random_start_word(Word *first_word);

void write_random_text(Word *first_word, char *outfile, int n_word, char start_word[30]);