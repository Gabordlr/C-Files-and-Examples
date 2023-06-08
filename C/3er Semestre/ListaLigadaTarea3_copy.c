#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
    struct nodo *siguiente;
};

struct nodo *indice = NULL;

int listaVacia();
int longitud();
void insertFinal(int num);
void insertInicial(int num);
void eliminarLista(int num);
void mostrarElementos();
void buscarNum(int num);
void eliminarPares();
void eliminarOcurrencia(int num);
void promedioNumeros();

void main()
{
insertFinal(2);
insertFinal(7);
insertFinal(4);
insertFinal(6);
insertFinal(3);
insertFinal(7);
insertFinal(1);
printf("La longitud de la lista es: %d \n", longitud());
mostrarElementos();

insertInicial(9);
insertInicial(4);
printf("La longitud de la lista es: %d \n", longitud());
mostrarElementos();

promedioNumeros();

buscarNum(4);
eliminarPares();
mostrarElementos();

eliminarOcurrencia(7);
mostrarElementos();
}

int listaVacia()
{
    if(indice==NULL)
        return 1;
    else
        return 0;
}

int longitud()
{
    struct nodo *temporal;
    int longitud=0;
    temporal = indice;
    while (temporal != NULL)
    {
        longitud++;
        temporal = temporal->siguiente;
    }
    return longitud;
}

void insertFinal(int num)
{
    printf("Nuevo elemento al final de la lista: %d\n",num);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if ( elemento == NULL)
    {
        printf("No se puede crear un elemento en la lista");
        return;
    }
    if(listaVacia()==1)
    {
        elemento->valor=num;
        elemento->siguiente=indice;
        indice = elemento;
        return;
    }
    
    struct nodo *indiceActual = indice;
    struct nodo *indiceAnterior = NULL;

    while(indiceActual!=NULL)
    {
        indiceAnterior=indiceActual;
        indiceActual=indiceActual->siguiente;
    }
    elemento->valor = num;
    elemento -> siguiente = NULL;
    indiceAnterior->siguiente = elemento;
}

void eliminarLista(int num){
  if(listaVacia()==1)
    {
        printf("La lista esta vacia\n");
        return;
    }

    struct nodo *indiceActual=indice;
    struct nodo *indiceAnterior=NULL;
    struct nodo *temporal1;

    while (indiceActual!=NULL)
    {
        if(indiceActual->valor==num)
        {
            if(indiceAnterior==NULL)
            {
                temporal1 = indiceActual;
                indice = indiceActual->siguiente;
                printf("Eliminado: %d\n", temporal1->valor);
                free(temporal1);
                return;
            }
            else
            {
                temporal1 = indiceActual;
                printf("Eliminado: %d\n", temporal1->valor);
                indiceAnterior->siguiente = indiceActual->siguiente;
                free(temporal1);
                return;
            }
        }
    indiceAnterior=indiceActual;
    indiceActual=indiceActual->siguiente;
    }
    printf("No se puedo eliminar el elemento %d de la lista", num);
}

void insertInicial(int num)
{
    printf("Nuevo elemento al prinipio de la lista: %d\n",num);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if ( elemento == NULL)
    {
        printf("No se puede crear un elemento en la lista");
        return;
    }

    elemento->valor=num;
    elemento->siguiente=indice;
    indice = elemento;
    return;
}

void mostrarElementos()
{
    int i=0;
    struct nodo *temporal;
    temporal = indice;
    printf("Elementos de la lista \n");
    while (temporal!=NULL){
        printf("Elementos[%d]= %d \n", i, temporal->valor);
        temporal = temporal->siguiente;
        i++;
    }
}

void buscarNum(int num)
{   
    printf("Buscando numero %d...\n", num);
    struct nodo *temporal;
    int cont=0, i=0;
    temporal = indice;
    while (temporal != NULL)
    {
        if (temporal->valor == num){
            cont++;
            printf("Elemento[%d]= %d \n", i, temporal->valor);
        }
        temporal = temporal->siguiente;
        i++;
    }
    printf("El numero %d se repite: %d \n", num, cont);
}

void eliminarPares()
{
    struct nodo *temporal;
    struct nodo *actual = indice;
    struct nodo *anterior=NULL;

    printf("Eliminando pares... \n"); 

    while (actual != NULL)
    {
        if (actual->valor%2 == 0){
            if(anterior==NULL)
            {
                temporal = actual;
                indice = actual->siguiente;
                printf("Eliminado: %d\n", temporal->valor);
                free(temporal);
            }
            else
            {
                temporal = actual;
                printf("Eliminado: %d\n", temporal->valor);
                anterior->siguiente = actual->siguiente;
                free(temporal);
            }
        }
        else{
            anterior=actual;
        }
        actual=actual->siguiente;
    }
}

void promedioNumeros()
{
    int sum=0;
    struct nodo *temporal;
    temporal = indice;
    printf("Elementos de la lista \n");
    while (temporal!=NULL){
        sum += temporal->valor;
        temporal = temporal->siguiente;
    }
    float prom = (float)sum/ (float)longitud();

    printf("EL promedio de los valores de la lista es: %f \n", prom);
}


void eliminarOcurrencia(int num)
{
    struct nodo *temporal;
    struct nodo *actual = indice;
    struct nodo *anterior=NULL;

    while (actual != NULL)
    {
        if (actual->valor == num){
            if(anterior==NULL)
            {
                temporal = actual;
                indice = actual->siguiente;
                printf("Eliminado: %d\n", temporal->valor);
                free(temporal);
            }
            else
            {
                temporal = actual;
                printf("Eliminado: %d\n", temporal->valor);
                anterior->siguiente = actual->siguiente;
                free(temporal);
            }
        }
        else{
            anterior=actual;
        }
        actual=actual->siguiente;
    }
}
