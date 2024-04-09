#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


vector_t* nuevo_vector(void) {
    vector_t* vector_nuevo = malloc(sizeof(vector_t));
    vector_nuevo -> capacity = 2; //inicializa con 2
    vector_nuevo -> size = 0; //tiene 0 elementos
    vector_nuevo -> array = NULL;

    return vector_nuevo;
}

uint64_t get_size(vector_t* vector) {
    return vector -> size;
}

void push_back(vector_t* vector, uint32_t elemento) {

    //Si el array esta vacio
    if (vector -> array == NULL){ //inicializo el array en memoria
        uint32_t *nuevo_array = malloc(sizeof(uint32_t)*(vector -> capacity)); //asigno espacio de memoria para el nuevo array
        nuevo_array[vector -> size] = elemento; 
        vector -> array = nuevo_array;
        vector -> size++;

    } else{
        //si hay capacidad en el array entonces agrego el nuevo elemento
        if(vector -> size < vector -> capacity){
            vector -> array[vector -> size] = elemento;
            vector -> size++;
        }

        else{ // Caso contrario aumento su capacidad para agregar más elementos 

        //realloc() cambia el tamaño del bloque de memoria asignado previamente a un nuevo tamaño especificado 
        vector -> capacity = vector -> capacity * 2; //aumento su capacidad 
        vector -> array = realloc(vector -> array, sizeof(uint32_t)*(vector -> capacity));
        vector -> array[vector -> size] = elemento;
        vector -> size++;
        }
    }
}

int son_iguales(vector_t* v1, vector_t* v2) {
    //Tienen la misma cantidad de elemntos?
    if(v1 -> size == v2-> size){
        //Compruebo si sus elemtos son iguales en su respectiva posición
        for (uint32_t i = 0; i < v1 -> size; i++){
            //Encontré distinto si:
            if (v1 -> array[i] != v2 ->array[i])
            {
                return 0; //cero -> False
            }
        }
        return 1;
    }

    return 0;
}

uint32_t iesimo(vector_t* vector, size_t index) {

uint32_t iesimo;
    //El indice NO es válido si:
    if (index >= vector -> size){
        return 0;
    } else{
        for (uint32_t i = 0; i < vector -> size; i++){ 
            if(i == index){
                iesimo = vector -> array[i];
            }
        }
    }
    return iesimo;
}

void copiar_iesimo(vector_t* vector, size_t index, uint32_t* out){
    *out = vector -> array[index]; //out apunta al iesimo elemento de mi array
}


// Dado un array de vectores, devuelve un puntero a aquel con mayor longitud.
vector_t* vector_mas_grande(vector_t** array_de_vectores, size_t longitud_del_array) {
    vector_t* vector_grande; //= malloc(sizeof(vector_t)); 

    vector_grande = array_de_vectores[0];
    for (size_t i = 0; i < longitud_del_array; i++){
        // ¿capacidad = longitud?
        if(vector_grande -> capacity < array_de_vectores[i] -> capacity){
            vector_grande = array_de_vectores[i];
        }
    }
    return vector_grande;
}
