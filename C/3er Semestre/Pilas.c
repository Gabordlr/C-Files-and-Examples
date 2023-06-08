#include <stdio.h>
#define MAX 5

struct  pila{
    int valores[MAX];
    int tope;
};

void inicializarPila(struct pila *instancia){
    instancia->tope=-1;
}

int pilaLlena(struct pila *instancia){
    //return (instancia->tope == MAX-1)? 1:0;
    if(instancia->tope == MAX-1){
        printf("La pila esta llena\n");
        return 1;
    }
    else{
        return 0;
    }
}

int pilaVacia(struct pila *instancia){
    //return (instancia->tope == -1)? 1:0;
    if(instancia->tope == -1){
        printf("La pila esta vacia\n");
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct pila *instancia, int numero){
    if (pilaLlena(instancia)==1)
        return;
    instancia->tope++;
    instancia->valores[instancia->tope]=numero;
}

void pop(struct pila *instancia){
    printf("Eliminado de la pila: %d\n",instancia->valores[instancia->tope]);
    if (pilaVacia(instancia)==1)
        return;
    instancia->valores[instancia->tope]=0;
    instancia->tope--;
}

void mostrarElementosPila(struct pila *instancia){
    int i;
    printf("Elementos en la pila\n");
    for(i=instancia->tope;i >= 0; i--)
        printf("Elemento[%d]=%d\n",i,instancia->valores[i]);
}

void main(){
    struct pila instanciaMain;
    printf("Uso de una pila de datos estaticos\n\n");
    inicializarPila(&instanciaMain);
    printf("Operaciones \"Push\"\n");
    push(&instanciaMain, 1);
    push(&instanciaMain, 2);
    push(&instanciaMain, 3);
    push(&instanciaMain, 4);
    mostrarElementosPila(&instanciaMain);
    printf("\n");
    printf("Operaciones \"pop\"\n");
    pop(&instanciaMain);
    pop(&instanciaMain);
    mostrarElementosPila(&instanciaMain);
    printf("\n");
    printf("Operaciones \"Push\"\n");
    push(&instanciaMain, 4);
    push(&instanciaMain, 5);
    mostrarElementosPila(&instanciaMain);

}