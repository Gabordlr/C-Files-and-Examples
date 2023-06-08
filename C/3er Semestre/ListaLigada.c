#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor;
    struct nodo *siguiente;
};

struct nodo *indice = NULL;

int listaVacia();
void longitud();
void insertFinal(int num);
void insertInicio(int num);
void eliminarLista(int num);

void main()
{
    insertFinal(2);
    insertFinal(7);
    insertFinal(4);
    insertFinal(6);
    insertFinal(3);
    longitud();
    mostrarElementos();
}

int listaVacia()
{
    if(indice==NULL) //-->  O(2)
        return 1;
    else
        return 0;
} //--> O(2)E -> O(1)G

void longitud()
{
    struct nodo *temporal; //-->  O(1)
    int longitud; //-->  O(1)
    temporal = indice; //-->  O(1)
    while (temporal != NULL) //-->  O(2n)
    {
        longitud++;
        temporal = temporal->siguiente;
    }
    printf("Longitud de lista:%d\n", longitud); //-->  O(1)   
} //--> O(2n+4)E -> O(n)G

void insertFinal(int num)
{
    printf("Nuevo elemento al final de la lista: %d\n",num); //-->  O(1)
    struct nodo *elemento = malloc(sizeof(struct nodo)); //-->  O(1)
    if ( elemento == NULL)
    {
        printf("No se puede crear un elemento en la lista");
        return;
    }
    else //-->  O(5)
    {
        elemento->valor=num;
        elemento->siguiente=indice;
        indice = elemento;
        return;
    }
    struct nodo *indiceActual = indice; //-->  O(1)
    struct nodo *indiceAnterior = NULL; //-->  O(1)

    while(indiceActual==NULL) //-->  O(2n)
    {
        indiceAnterior=indiceActual;
        indiceAnterior=indiceActual->siguiente;
    }
    elemento->valor = num; //-->  O(1)
    elemento -> siguiente = NULL; //-->  O(1)
    indiceActual->siguiente = elemento; //-->  O(1)
} //--> O(2n+12)E -> O(n)G

void eliminarLista(int num){
  if(listaVacia()==1) //-->  O(3) + O(1)
    {
        printf("La lista esta vacia\n");
        return;
    }

    struct nodo *indiceActual=indice; //-->  O(1)
    struct nodo *indiceAnterior=NULL; //-->  O(1)
    struct nodo *temporal1; //-->  O(1)

    while (indiceActual!=NULL) //-->  O(14n)
    {
        if(indiceActual->valor==num) //-->  O(12)
        {
            if(indiceAnterior==NULL) //-->  O(6)
            {
                temporal1 = indiceActual; //-->  O(1)
                indice = indiceActual->siguiente; //-->  O(1)
                printf("Eliminado: %d\n", temporal1->valor); //-->  O(1)
                free(temporal1); //-->  O(1)
                return; //-->  O(1)
            }
            else //-->  O(6)
            {
                temporal1 = indiceActual; //-->  O(1)
                printf("Eliminado: %d\n", temporal1->valor); //-->  O(1)
                indiceAnterior->siguiente = indiceActual->siguiente; //-->  O(1)
                free(temporal1); //-->  O(1)
                return; //-->  O(1)
            }
        }
    indiceAnterior=indiceActual; //-->  O(1)
    indiceActual=indiceActual->siguiente; //-->  O(1)
    }
    printf("No se puedo eliminar el elemento %d de la lista", num); //-->  O(1)
} //--> O(14n+7)E -> O(n)G

