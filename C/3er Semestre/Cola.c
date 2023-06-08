#include <stdio.h>
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

void main()
{
struct cola instanciaMain;
printf("Uso de una cola de datos estaticos\n\n");
iniciarCola(&instanciaMain);
queue(&instanciaMain, 1);
queue(&instanciaMain, 2);
queue(&instanciaMain, 3);
queue(&instanciaMain, 4);

mostrarElementosCola(&instanciaMain);

printf("\nOperaciones dequeue\n\n");
dequeue(&instanciaMain);
dequeue(&instanciaMain);

mostrarElementosCola(&instanciaMain);

printf("\nOperaciones queue");
queue(&instanciaMain, 10);
queue(&instanciaMain, 11);
queue(&instanciaMain, 12);

mostrarElementosCola(&instanciaMain);

}

void iniciarCola(struct cola *instancia){
    instancia ->frente = 0;
    instancia ->atras=0;
}

int colaVacia( struct cola *instancia){
    if (instancia ->frente == instancia ->atras)
    {
        printf("La cola esta vacia\n");
        return 1;
    }
    else
        return 0;
}

int colaLlena(struct cola *instancia){
    if (instancia ->atras == MAX)
    {
        printf("La cola esta llena\n");
        return 1;
    }
    else
        return 0;
}

void queue(struct cola *instancia, int numero){
    printf("Nuevo elemento de la cola:%d \n", numero);
    if(colaLlena(instancia)==1)
        return;
    else 
    {
        instancia->valores[instancia->atras] = numero;
        instancia ->atras++;
    }
}

void dequeue(struct cola *instancia){
    printf("Eliminando de la cola:%d\n", instancia->valores[instancia->frente]);
    if(colaVacia(instancia)==1)
        return;
    else{
        int i;
        instancia->valores[instancia->frente] = 0;
        for(i=0; i < (instancia->atras-1); i++)
            instancia -> valores[i] = instancia->valores[i+1];
        instancia->valores[instancia->atras]=0;
        instancia->atras--;
    }
}

void mostrarElementosCola(struct cola *instancia){
    printf("Elemetnos en la cola:\n");
    if (colaVacia(instancia)==1)
        return;
    else{
        int i;
        for(i=instancia->frente; i<instancia->atras;i++)
        printf("Elementos[%d]=%d\n",i,instancia->valores[i]);
    }
}

