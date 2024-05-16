#include "txt_writer.h"


/* 
Funzione che controlla se ci sono le parole ".","!" e "?" e in base a quante ce ne sono
tra le parole del csv randomizza una di quelle presenti e scrive una parola a caso
tra le successive di quella scelta
*/
Word *random_start_word(Word *first_word){
    // crea un seed per non avere gli stessi numeri random
    srand(time(NULL));

    char quest_str[30];
    char escl_str[30];
    quest_str[0]='?';
    escl_str[0]='!';

    // controlla quali punteggiature sono presenti nel csv e salva i puntatori
    Word *point=first_word;
    Word *question=search_word(first_word,quest_str);
    Word *esclamation=search_word(first_word,escl_str);
    Tuple *start_point;


    /*
    controlla quali puntatori esistono (cioè la parola è nel csv) e randomizza la punteggiatura
    da cui iniziare
    */
    float sum;
    if(question!=NULL && esclamation!=NULL){
        int num=rand()%3;
        if(num==0){
            sum=point->count;
            start_point=(Tuple *)point->first_tuple;
        }
        else if(num==1){
            sum=question->count;
            start_point=(Tuple *)question->first_tuple;
        }
        else{
            sum=esclamation->count;
            start_point=(Tuple *)esclamation->first_tuple;
        }
    }
    else if(question!=NULL){
        int num=rand()%2;
        if(num==0){
            sum=point->count;
            start_point=(Tuple *)point->first_tuple;
        }
        else{
            sum=question->count;
            start_point=(Tuple *)question->first_tuple;
        }
    }
    else if(esclamation!=NULL){
        int num=rand()%2;
        if(num==0){
            sum=point->count;
            start_point=(Tuple *)point->first_tuple;
        }
        else{
            sum=esclamation->count;
            start_point=(Tuple *)esclamation->first_tuple;
        }
    }
    else{
        sum=point->count;
        start_point=(Tuple *)point->first_tuple;
    }


    // randomizza una tra le tuple collegate alla punteggiatura selezionata casualmente
    double num_r =((float)rand()/(float)(RAND_MAX)) * sum;
    while(num_r-start_point->count>0){
        num_r-=start_point->count;
        start_point=(Tuple *)start_point->next_tuple;
    }
    

    return search_word(first_word,start_point->name);
}


/* 
Funzione che prende in input un file su cui scrivere, la prima parola
della lista puntata, il numero di parole da scrivere e la possibile prima parola
e scrive il testo random sul file txt
*/
void write_random_text(Word *first_word, char *outfile, int n_word, char start_word[30]){
    if(n_word<=0){
        printf("Numero di parole non inserito o non valido\n");
        exit(1);
    }
    
    FILE *file_out=fopen(outfile,"w");
    if(file_out==0){
        printf("Errore nell'apertura del file di output!\n");
        exit(0);
    }
    
    // se è stata data la prima parola da riga di comando vede se c'è nel csv
    Word *start;
    if (start_word!=NULL){
        start=search_word(first_word,start_word);
        if(start==NULL){
            start_word=NULL;
        }
    }


    // se non è stata data una prima parola la randomizza
    if(start_word==NULL){
        start=random_start_word(first_word);
        printf("Parola iniziale non inserita o non presente!\n");
    }
    printf("Testo di %d parole creato partendo dalla parola random: %s\n",n_word,start->name);
    


    // scrive per numword volte una parola e poi randomizza la successiva tra le Tuple collegate
    Tuple *tuple_pointer;
    char upper[30];
    double num_r;
    char last_written[30]=".";
    int n_word_write=0;
    while(n_word>0){
        // controlla se l'ultima parola è una punteggiatura e rende maiuscola la lettera dopo
        if(strcmp(last_written,".")==0 || strcmp(last_written,"!")==0 || strcmp(last_written,"?")==0){
            strcpy(upper,start->name);
            if(upper[0]==-61){
                upper[1]=upper_lowercase(upper[1]);
            }
            else{
                upper[0]=upper_lowercase(upper[0]);
            }
            fprintf(file_out,"%s ",upper);
        }
        else{
            fprintf(file_out,"%s ",start->name);
        }
        strcpy(last_written,start->name);
        // randomizza un numero e lo sottrae con le probabilità delle singole Tuple finchè
        // non arriva a 0
        num_r =((float)rand()/(RAND_MAX)) * start->count;
        tuple_pointer=(Tuple *)start->first_tuple;
        while(num_r-tuple_pointer->count>0){
            num_r=num_r-tuple_pointer->count;
            if(tuple_pointer->next_tuple!=NULL){
                tuple_pointer=(Tuple *)tuple_pointer->next_tuple;
            }
        }
        start=(Word *)tuple_pointer->self_word;
        n_word--;
        n_word_write++;
        if(n_word_write%15==0){
            fprintf(file_out,"\n");
        }
    }
}


