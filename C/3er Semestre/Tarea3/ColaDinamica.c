#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int valor;
    struct nodo *siguiente;
};

struct nodo *frente = NULL;
struct nodo *atras = NULL;

int colaVacia();
void queue(int numero);
void dequeue();
void mostrarElementosCola();

void main()
{
    printf("Uso de una cola dinamica de datos\n\n");
    printf("Operaciones \"queue\"\n");
    queue(1);
    queue(2);
    queue(3);
    queue(4);
    mostrarElementosCola();
    printf("\n");
    printf("Operaciones \"dequeue\"\n");
    dequeue();
    dequeue();
    mostrarElementosCola();
    printf("\n");
    printf("Operaciones \"queue\"\n");
    queue(3);
    queue(4);
    queue(5);
    mostrarElementosCola();
}

int colaVacia(){
    if (frente == NULL)
        return 1;
    else
        return 0;
}

void queue(int numero){
    printf("Nuevo elemento en la cola: %d\n", numero);
    struct nodo *elemento = malloc(sizeof(struct nodo));
    if (elemento == NULL){
        printf("No se pueden crear elementos en la cola");
    }
    elemento->valor=numero;
    elemento->siguiente=NULL;
    if (colaVacia() == 1){
        frente = elemento;
        atras = elemento;
    }
    else{
        atras->siguiente = elemento;
        atras = elemento;
    }
}

void dequeue(){
    if (colaVacia==1){
        printf("La cola esta vacia\n");
        return;
    }
    else{
        struct nodo *temporal;
        temporal = frente;
        if (frente == atras){
            frente = NULL;
            atras = NULL;
        }
        else
            frente=frente->siguiente;
        printf("Eliminando de la cola: %d\n", temporal->valor);
        free(temporal);
    }
}

void mostrarElementosCola(){
    int i=0;
    struct nodo *temporal;
    temporal = frente;
    printf("Elementos en la cola:\n");
    while (temporal != NULL){
        printf("Elemento[%d] = %d\n", i, temporal->valor);
        temporal = temporal -> siguiente;
        i++;
    }
}
