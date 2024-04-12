
#include <stdbool.h>


bool is_ascii_accepted(char current_char){
    /* 
    Preso il carattere controlla se ha un valore ASCII tra quelli accettati
    nelle parole:
    RANGE_ASCII=[(48,57),(65,90),(97,122),(128,155),(160,167),(208,216),(224,237)]
    ASCII_SINGLE=[157,181,182,183,198,199,222]
    */
    if(current_char>=0 && current_char<48){
        return false;
    }
    if(current_char>57 && current_char<65){
        return false;
    }
    if(current_char>90 && current_char<97){
        return false;
    }
    if(current_char>122 && current_char<128){
        return false;
    }
    if(current_char>155 && current_char<160 && current_char!=157){
        return false;
    }
    if(current_char>167 && current_char<181){
        return false;
    }
    if(current_char>183 && current_char<208 && current_char!=198 && current_char!=199){
        return false;
    }
    if(current_char>216 && current_char<224 && current_char!=222){
        return false;
    }
    if(current_char>237){
        return false;
    }
    return true;
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
    if(current_char>=65 && current_char<=90){
            return current_char+32;
        }
    return current_char;
}