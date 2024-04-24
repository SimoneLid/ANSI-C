#include "ascii_control.h"


bool is_ascii_accepted(char current_char){
    /* 
    Preso il carattere controlla se ha un valore ASCII tra quelli accettati
    nelle parole:
    RANGE_ASCII=[(48,57),(65,90),(97,122)]
    */
    if(current_char>=48 && current_char<=57){
        return true;
    }
    if(current_char>=65 && current_char<=90){
        return true;
    }
    if(current_char>=97 && current_char<=122){
        return true;
    }
    return false;
}

bool is_ascii_accepted_2b(char current_char){
    /* 
    Preso il carattere controlla se ha un valore ASCII tra quelli accettati
    nelle parole:
    RANGE_2B=[(-128,-106),(-104,-74),(-72,-65)]
    */
    if((unsigned char)current_char>=128 && (unsigned char)current_char<=150){
        return true;
    }
    if((unsigned char)current_char>=152 && (unsigned char)current_char<=182){
        return true;
    }
    if((unsigned char)current_char>=184 && (unsigned char)current_char<=191){
        return true;
    }
    return false;
}


bool is_punct_accepted(char current_char){
    /* 
    Preso il carattere controlla se è una punteggiatura che termina
    una frase e va salvata
    */
    if(current_char=='.' || current_char=='!' || current_char=='?'){
        return true;
    }
    return false;
}

char lower_uppercase(char current_char){
    /* 
    Preso il carattere controlla se è una lettera maiuscola e la trasforma
    in minuscola
    */
    if((current_char>=65 && current_char<=90) ||((unsigned char)current_char>=128 && (unsigned char)current_char<=158)){
            return current_char+32;
        }
    return current_char;
}

char upper_lowercase(char current_char){
        /* 
    Preso il carattere controlla se è una lettera minuscola e la trasforma
    in maiuscola
    */
    if((current_char>=97 && current_char<=122) || ((unsigned char)current_char>=160 && (unsigned char)current_char<=190)){
            return current_char-32;
        }
    return current_char;

}