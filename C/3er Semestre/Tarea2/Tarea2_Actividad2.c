#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define MAX 5

//Definicion de la estructura de la cola
struct cola
{
    int valores[MAX];
    int frente,atras;
};

//inicializar
void iniciarCola(struct cola *instancia);
int colaVacia(struct cola *instaancia);
int colaLlena(struct cola *instancia);
void queue(struct cola *instancia, int numero);
void dequeue(struct cola *instancia);
void mostrarElementosCola(struct cola *instancia);

int main(){
    struct cola instanciaMain;
    iniciarCola(&instanciaMain);

    srand(time(NULL)); 
    int i, num;

    for (i=0;i<=5;i++)
        queue(&instanciaMain, rand()%5);

    mostrarElementosCola(&instanciaMain);

    for (i=0;i<=5;i++)
    

    mostrarElementosCola(&instanciaMain);
}

void iniciarCola(struct cola *instancia){
    instancia ->frente = 0;
    instancia ->atras=0;
}

int colaVacia( struct cola *instancia){
    if (instancia ->frente == instancia ->atras) //-->  O(3)
    {
        printf("La cola esta vacia\n");
        return 1;
    }
    else
        return 0;
} //-->  O(3)E -> O(1)G
int colaLlena(struct cola *instancia){
    if (instancia ->atras == MAX) //-->  O(3)
    {
        printf("La cola esta llena\n");
        return 1;
    }
    else
        return 0;
} //-->  O(3)E -> O(1)G

void queue(struct cola *instancia, int numero){
    printf("Nuevo elemento de la cola:%d \n", numero); //-->  O(1)
    if(colaLlena(instancia)==1)
        return;
    else //-->  O(3)
    {
        instancia->valores[instancia->atras] = numero;
        instancia ->atras++;
    }
} //-->  O(4)E -> O(1)G
void dequeue(struct cola *instancia){
    printf("Eliminando de la cola:%d\n", instancia->valores[instancia->frente]); //-->  O(1)
    if(colaVacia(instancia)==1)
        return;
    else{ //-->  O(n+4)
        int i; //-->  O(1)
        instancia->valores[instancia->frente] = 0; //-->  O(1)
        for(i=0; i < (instancia->atras-1); i++) //-->  O(n)
            instancia -> valores[i] = instancia->valores[i+1];
        instancia->valores[instancia->atras]=0; //-->  O(1)
        instancia->atras--; //-->  O(1)
    }
} //-->  O(n+5)E -> O(n)G
void mostrarElementosCola(struct cola *instancia){
    printf("Elemetnos en la cola:\n"); //-->  O(1)
    if (colaVacia(instancia)==1)
        return;
    else{ //-->  O(n+1)
        int i; //-->  O(1)
        for(i=instancia->frente; i<instancia->atras;i++) //-->  O(n)
            printf("Elementos[%d]=%d\n",i,instancia->valores[i]);
    }
} //-->  O(n+2)E -> O(n)G

