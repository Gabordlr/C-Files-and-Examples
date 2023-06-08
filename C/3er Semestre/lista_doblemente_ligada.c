// Libreria de entrada y salida de datos
#include <stdio.h>
// Libreria para el manejo de memoria
#include <stdlib.h>
// Definicion de la estructura de un nodo en la Lista
struct nodo
{
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
};

// Elemento que apunta a la parte inicial de la Lista
struct nodo *inicio = NULL;

// Elemento que apunta a la parte final de la Lista
struct nodo *fin = NULL;

int listaVacia()
{
    if (inicio == NULL) //&& fin == NULL)
        return 1;
    else
        return 0;
}

int longitudLista(){
    struct nodo *temporal;
    int longitud;
    temporal = inicio; //si quisiera recorrer al revés, temporal = fin
    while(temporal != NULL){
        longitud++;
        temporal = temporal->siguiente; //si quisiera recorrer al revés, temporal = temporal->anterior
    }
    return longitud;
}

void insertaFinalLista(int numero){
    printf("Nuevo elemento al final de la Lista: %d",numero);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if (elemento == NULL){//vacía
        printf("No se puede crear un elemento en la lista");
        return;
    }
    if (listaVacia() == 1){
        elemento -> valor = numero;
        elemento -> siguiente = NULL;
        elemento -> anterior = NULL;
        inicio = elemento;
        fin = elemento;
    }
    else
    {
        elemento->valor = numero;
        elemento->siguiente = NULL;
        elemento->anterior = fin;
        fin->siguiente = elemento;
        fin = elemento;
    }
    
}

void insertaInicioLista(int numero){
    printf("Nuevo elemento al inicio de la Lista: %d",numero);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if (elemento == NULL){//vacía
        printf("No se puede crear un elemento en la lista");
        return;
    }
    if (listaVacia() == 1){
        elemento -> valor = numero;
        elemento -> siguiente = NULL;
        elemento -> anterior = NULL;
        inicio = elemento;
        fin = elemento;
    }
    else
    {
        inicio->anterior=elemento;
        elemento->valor=numero;
        elemento->siguiente=inicio;
        elemento->anterior=NULL;
        inicio = elemento;
    }
}

void eliminaLista(int numero){
    if(listaVacia() == 1){
        printf("La lista está vacía \n");
        return;
    }
    struct nodo *indiceAnterior = NULL;
    struct nodo *indiceActual = inicio;
    struct nodo *indiceSiguiente = inicio->siguiente;
    struct nodo *temporal;
}
int main() {}