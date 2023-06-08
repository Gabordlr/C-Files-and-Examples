#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
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
    if(instancia->tope == -1){ //-->  O(3)
        printf("La pila esta vacia\n");
        return 1;
    }
    else{
        return 0;
    }
} //--> O(3)E -> O(1)G

void push(struct pila *instancia, int numero){ 
    if (pilaLlena(instancia)==1) //-->  O(2) + O(1)
        return;
    instancia->tope++; //-->  O(1)
    instancia->valores[instancia->tope]=numero; //-->  O(1)
} //--> O(5)E -> O(1)G

void pop(struct pila *instancia){
    printf("Eliminado de la pila: %d\n",instancia->valores[instancia->tope]); //-->  O(1)
    if (pilaVacia(instancia)==1) //-->  O(2) + O(1)
        return;
    instancia->valores[instancia->tope]=0; //-->  O(1)
    instancia->tope--; //-->  O(1)
} //--> O(6)E -> O(1)G

void mostrarElementosPila(struct pila *instancia){
    int i; //-->  O(1)
    printf("Elementos en la pila\n"); //-->  O(1)
    for(i=instancia->tope;i >= 0; i--) //-->  O(n)
        printf("Elemento[%d]=%d\n",i,instancia->valores[i]);
} //-->  O(n+2)E -> O(n)G

int main(){
    struct pila instanciaMain;
    inicializarPila(&instanciaMain);
    srand (time(NULL)); 

    int i, decision, tam, num;
    printf("Ingrese numero de operaciones: ");
    scanf("%d", &tam);

    for (i=0;i<tam;i++){
        decision = rand()%10;
        if (decision%2==0){
            num = rand()%10;
            printf("Se agrega el numero, %d\n", num);
            push(&instanciaMain, num);
    }
        else{
            printf("Se elimina un valor\n");
            pop(&instanciaMain);   
    }
    mostrarElementosPila(&instanciaMain);
    }

}
