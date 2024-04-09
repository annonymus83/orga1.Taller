#include "classify_chars.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void classify_chars_in_string(char* string, char** vowels_and_cons) {
    vowels_and_cons[0] = calloc(65, sizeof(char)); //vocales, defino en memoria 65 espacios inicilizados con ceros
    vowels_and_cons[1] = calloc(65, sizeof(char)); //consonantes, defino en memoria 65 espacios inicilizados con ceros

    int i = 0;
    int indice_consonante = 0;
    int indice_vocales = 0;

    while (string[i] != '\0'){
        //Caso es consonante
        if((string[i] != 'a') && (string[i] != 'e') && (string[i] != 'i')
         && (string[i] != 'o') && (string[i] != 'u')){
            vowels_and_cons[1][indice_consonante] = string[i];
            indice_consonante++; //el siguiente en caso de que exista
        }
        //caso es Vocal 
        else{
            vowels_and_cons[0][indice_vocales] = string[i];
            indice_vocales++; //el siguiente en caso de que exista
        }
        i++;
    }

    //Debemos finalizar su lectura con un '\0'.
    vowels_and_cons[1][indice_consonante] = '\0';
    vowels_and_cons[0][indice_vocales] = '\0';

}

void classify_chars(classifier_t* array, uint64_t size_of_array) {
    
    for (uint64_t i = 0; i < size_of_array; i++){
        array[i].vowels_and_consonants = malloc(2*sizeof(char*));
        classify_chars_in_string(array[i].string, array[i].vowels_and_consonants);
    }   
}

// []
