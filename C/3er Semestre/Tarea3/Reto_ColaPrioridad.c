#include <stdlib.h>
#include <stdio.h>

struct cola{
    int valor;
    int prioridad;
    struct cola *siguiente;
};

struct cola *frente = NULL;
struct cola *atras = NULL;

int colaVacia(){
    if (frente == NULL)
        return 1;
    else
        return 0;
}

void queue(int numero, int prio){
    printf("Nuevo elemento en la cola: %d  (%d)\n", numero, prio);
    struct cola *elemento = malloc(sizeof(struct cola)); 
    if (elemento == NULL){
        printf("No se pueden crear elementos en la cola");
    }
    elemento->valor=numero;
    elemento->prioridad=prio;
    elemento->siguiente=NULL;

    if (colaVacia() == 1){
        frente = elemento;
        atras = elemento;
    }
    else{
        struct cola *temporal;
        temporal = frente;
        while (temporal != NULL){
            if(temporal == frente && temporal->prioridad <= prio){
                elemento->siguiente = frente;
                frente = elemento;
                return;
            }
            if(temporal == atras){
                temporal->siguiente = elemento;
                atras = elemento;
                return;
            }
            if (temporal->prioridad >= prio && temporal->siguiente->prioridad <= prio){
                elemento->siguiente = temporal->siguiente;
                temporal->siguiente = elemento;
                return;
            }
            temporal = temporal -> siguiente;   
        }
    }
}

void mostrarElementosCola(){
    int i=0;
    struct cola *temporal;
    temporal = frente;
    printf("Elementos en la cola:\n");
    while (temporal != NULL){
        printf("Elemento[%d] = %d  (%d)\n", i, temporal->valor, temporal->prioridad);
        temporal = temporal -> siguiente;
        i++;
    }
}

void dequeue(){
    if (colaVacia==1){
        printf("La cola esta vacia\n");
        return;
    }
    else{
        struct cola *temporal;
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

void longitud(){
    int i=0;
    struct cola *temporal;
    temporal = frente;
    printf("Longitud de la cola:\n");
    while (temporal != NULL){
        temporal = temporal -> siguiente;
        i++;
    }
    printf("Longitud: %d \n", i);
}

void queue_varios(int n, int lista[n][2]){
    int i;
    for (i=0; i < n;i++)
        queue(lista[i][0], lista[i][1]);
}

void eliminarCola(){
    struct cola *temporal;
    temporal = frente;
    printf("Eliminando cola...\n");
    while (temporal != NULL){
        free(temporal);
        temporal = temporal -> siguiente;
    }
    frente = NULL;
    atras = NULL;
    if (colaVacia()==1){
        printf("Cola eliminada de forma exitosa \n");
    }
}

void buscarElemento(int num){
    int i=0;
    struct cola *temporal;
    temporal = frente;
    printf("Buscando elemento \"%d\" ...\n", num);
    while (temporal != NULL){
        if (temporal->valor == num)
            printf("Elemento[%d] = %d  (%d)\n", i, temporal->valor, temporal->prioridad);
        temporal = temporal -> siguiente;
        i++;
    }
}

void buscarPrioridad(int prio){
    int i=0;
    struct cola *temporal;
    temporal = frente;
    printf("Buscando elementos con prioridad \"%d\" ...\n", prio);
    while (temporal != NULL){
        if (temporal->prioridad == prio)
            printf("Elemento[%d] = %d  (%d)\n", i, temporal->valor, temporal->prioridad);
        temporal = temporal -> siguiente;
        i++;
    }
}


void main() 
{
    int lista[5][2] = {{5, 6},{2, 1},{7, 4},{7, 4},{9, 5}};

    int size = sizeof(lista)/sizeof(lista[0]);

    printf("Uso de una cola dinamica de datos\n\n");
    printf("Operaciones \"queue\"\n");

    queue_varios(size, lista);

    queue(1, 2);
    queue(2, 3);
    queue(3, 4);
    queue(4, 2);
    mostrarElementosCola();
    printf("\n");
    printf("Operaciones \"dequeue\"\n");
    dequeue();
    dequeue();
    mostrarElementosCola();
    printf("\n");
    printf("Operaciones \"queue\"\n");
    mostrarElementosCola();
    longitud();

    buscarElemento(2);
    buscarPrioridad(4);

    eliminarCola();
}
