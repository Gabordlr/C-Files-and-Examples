#include <stdio.h>
#include <stdlib.h>

struct nodo //objeto
{
    int valor;
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *raiz = NULL; //global
void insertarNodo(int); //insertar en arbol binario
void borrarArbol(struct nodo *elemento); //borra todo el árbol, usa recursividad
void recorridoPreOrder(struct nodo *inicial); //hace recorrido pre order (raiz - hijo izquierdo - hijo derecho)
void recorridoInOrder(struct nodo *inicial);//recorrido in order (hijo izquierdo - raiz - hijo derecho)
void recorridoPostOrder(struct nodo *inicial); //recorrido post order ( hijo izquierdo - hijo derecho - raiz)
void borrarNodo(struct nodo *incial, int); //borrar un nodo específico del árbol;

void main()
{
    
    printf("\033[1mArból Binario\n\n\e[0m");
    printf("\033[32;3m Operaciones \"incersión\"\n\e[0m");
    insertarNodo(10);
    insertarNodo(5);
    insertarNodo(14);
    insertarNodo(7);
    insertarNodo(12);
    printf("\n");
    printf("\033[33;3m Operaciones \"recorrido pre-order\"\n\e[0m");
    recorridoPreOrder(raiz);
    printf("\n\n");
    printf("\033[32;3m Operaciones \"recorrido in-order\"\n\e[0m");
    recorridoInOrder(raiz);
    printf("\n\n");
    printf("\033[34;3m Operaciones \"recorrido post-order\"\n\e[0m");
    recorridoPostOrder(raiz);
    printf("\n\n");
    printf("\033[31;3m Operaciones \"eliminar\"\n\e[0m");
    borrarArbol(raiz);


    
}

void insertarNodo(int num)
{
    struct nodo *nuevo= malloc(sizeof(struct nodo));
    nuevo->valor = num;
    nuevo->izquierda = NULL;
    nuevo->derecha=NULL;
    printf("\033[1mSe incerta el nodo %d en árbol binário\n\e[0m",num);
    //no hay elementos:
    if (raiz == NULL)
    {
        raiz = nuevo;
    }
    //si hay elementos:
    else
    {
        //indices para recorrido:
        struct nodo *IndiceAnt;
        struct nodo *IndiceAct;
        IndiceAnt = NULL;
        IndiceAct = raiz; //para empezar de aquí
        //recorrido:
        while (IndiceAct != NULL)
        {
            IndiceAnt = IndiceAct;
            //si el num es menor entonces izquierda
            if(num < IndiceAct->valor)
                IndiceAct = IndiceAct->izquierda;
            else
                IndiceAct = IndiceAct->derecha;
        }
        //Al llegar al final se incerta dependiendo si es mayor o menor
        if (num < IndiceAnt ->valor)
        {
            IndiceAnt ->izquierda = nuevo; //si es menor que el ultimo se va a la izquierda
        }    
        else
            IndiceAnt ->derecha = nuevo;
    }
    
}
void borrarArbol(struct nodo *elemento)
{
   //se eliminan en el orden en el que entrar 
    if(elemento!=NULL)
    {
        printf("\033[31;1mEliminar nodo con valor %d\n\e[0m",elemento->valor);
        borrarArbol(elemento->izquierda);
        borrarArbol(elemento->derecha);
        free(elemento);
    }
}
void recorridoPreOrder(struct nodo *inicial)
{
    if (inicial != NULL) //recorre desde raiz
    {
        //recursivamente recorrido pre order, primero raiz, luego izquierda y luego derecha
        printf("\033[33;1m  %d   \e[0m", inicial->valor);
        recorridoPreOrder(inicial->izquierda);
        recorridoPreOrder(inicial->derecha);
    }
}
void recorridoInOrder(struct nodo *inicial)
{
    if(inicial != NULL)
    {
        //recursivamente recorrido in order
        recorridoInOrder(inicial->izquierda);
        printf("\033[32;1m  %d  \e[0m", inicial->valor);
        recorridoInOrder(inicial->derecha);

    }
}
void recorridoPostOrder(struct nodo *inicial)
{
    if(inicial!=NULL)
    {
        recorridoPostOrder(inicial->izquierda);
        recorridoPostOrder(inicial->derecha);
        printf("\033[34;1m   %d  \e[0m",inicial->valor);
    }
}
void borrarNodo(struct nodo *incial, int num)
{
    
}
