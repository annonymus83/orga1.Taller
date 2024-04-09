#include "lista_enlazada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


lista_t* nueva_lista(void) {
    lista_t *lista_nueva = malloc(sizeof(lista_t));
    lista_nueva -> head = NULL;
    return lista_nueva;
}

uint32_t longitud(lista_t* lista) {
    nodo_t *actual = lista -> head;
    uint32_t longitud_de_lista = 0;
    while (actual != NULL)
    {
        longitud_de_lista++;
        actual = actual -> next;
    }
    return longitud_de_lista;
}

void agregar_al_final(lista_t* lista, uint32_t* arreglo, uint64_t longitud) {
    nodo_t* actual = lista -> head; //Apunto al primer elemento de la lista

    //Tener en cuenta que debo asignarles memoria a los nuevos elemtos a agregar
    //sizeof(type_t) me devuelve en Bytes el tamaño que ocupa ese tipo de dato
    // La función malloc() asigna memoria dinámicamente en el heap. 
    // Recibe como argumento el número de bytes que se desea reservar
    nodo_t* nuevo = malloc(sizeof(nodo_t)); 
    
     //el tamaño del array es igual a su longitud en 32bits
    uint32_t* array_nuevo = malloc(sizeof(uint32_t)*longitud);
    //Cada elemento del parametro "arreglo" debe asignarse al array_nuevo
    for (uint32_t i = 0; i < longitud; i++) //i Tiene tamaño 32bits dado que el arreglo es de 32bits
    {
        array_nuevo[i] = arreglo[i];
    }

    nuevo->longitud = longitud;
    nuevo->arreglo = array_nuevo;
    nuevo-> next = NULL;

    if(actual == NULL){ //si la lista esta vacia entonces el nuevo sera el primer elto
        lista -> head = nuevo;
    }
    else{
        while ((actual -> next) != NULL) //Si el siguiente elemento de mi lista NO es NULL
        {
            actual = actual -> next; //Avanzo al siguiente
        }

        actual -> next = nuevo; //caso contrario el siguiente será el nuevo
    }
}

nodo_t* iesimo(lista_t* lista, uint32_t i) {
    nodo_t* actual = lista -> head;
    uint32_t j = 0;
    while (j != i)
    {
        actual = actual -> next;
    }
    return actual;
}

uint64_t cantidad_total_de_elementos(lista_t* lista) {
    uint64_t total_elntos_arrays = 0; // es el resultado de la suma de la longitud de cada array
    nodo_t* actual = lista -> head; 

    while(actual != NULL){
        uint64_t l = actual -> longitud;
        total_elntos_arrays = total_elntos_arrays + l;
        actual = actual -> next;
    }
    return total_elntos_arrays;
}

void imprimir_lista(lista_t* lista) {
    nodo_t* actual = lista -> head;
    while (actual != NULL){
        uint64_t l = actual -> longitud;
        printf("%ld\n",l);
        actual = actual -> next;
    }
    //como imprimir null?
}

// Función auxiliar para lista_contiene_elemento
int array_contiene_elemento(uint32_t* array, uint64_t size_of_array, uint32_t elemento_a_buscar) {
    int verdad = 0;
    for (uint32_t i = 0; i < size_of_array; i++)
    {
        if (array[i] == elemento_a_buscar)
        {
            verdad = 1;
        }      
    }
    return verdad;
}

int lista_contiene_elemento(lista_t* lista, uint32_t elemento_a_buscar) {
    nodo_t* actual = lista -> head;
    int verdad = 0; // 0 = FALSE
    while (actual != NULL){
        if(array_contiene_elemento(actual -> arreglo, actual -> longitud, elemento_a_buscar) == 1){
            verdad = 1;
        }
        actual = actual -> next;
    }
    return verdad;
}


// Devuelve la memoria otorgada para construir la lista indicada por el primer argumento.
// Tener en cuenta que ademas, se debe liberar la memoria correspondiente a cada array de cada elemento de la lista.
void destruir_lista(lista_t* lista) {
    nodo_t* actual = lista ->head;

    while (actual != NULL){
        nodo_t* siguiente = actual -> next; //Debo guardar el siguiente nodo a liberar, antes de liberarlo 
        free(actual->arreglo);
        free(actual);
        actual = siguiente;
    }
    //lista -> head = NULL; //Para indicar que la lista esta vacia Preguntar?
}