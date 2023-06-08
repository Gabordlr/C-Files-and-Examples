#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int valor;
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *raiz=NULL;

void insertarNodo(int numero);
void borrarArbol(struct nodo *elemento);
void recorridoPreorder(struct nodo *inicial);
void recorridoInorder(struct nodo *inicial);
void recorridoPostorder(struct nodo *inicial);
int contarNodos(struct nodo *inicial, int cont);
int sumarArbol(struct nodo *inicial, int sum);

void main(){
    printf("Uso de una arbol binario\n\n");
    printf("Operaciones \"insercion\"\n");
    insertarNodo(10);
    insertarNodo(5);
    insertarNodo(14);
    insertarNodo(7);
    insertarNodo(12);
    printf("\n");
    printf("Operaciones \"recorrido preorden\"\n");
    recorridoPreorder(raiz);
    printf("\n\n");
    printf("Operaciones \"recorrido inorder\"\n");
    recorridoInorder(raiz);
    printf("\n\n");
    printf("Operaciones \"recorrido postorder\"\n");
    recorridoPostorder(raiz);
    printf("\n\n");
    printf("Numero de nodos en el arbol es = %d", contarNodos(raiz,0));
    printf("\n\n");
    printf("La suma del arbol es = %d", sumarArbol(raiz,0));
    printf("\n\n");
    printf("Operaciones \"eliminar\"\n");
    borrarArbol(raiz);
}

void insertarNodo(int numero){
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->valor=numero;
    nuevo -> izquierda=NULL;
    nuevo->derecha=NULL;
    printf("Se inserta el nodo con el valor %d en el arbol binario \n", numero);

    if (raiz == NULL)
        raiz=nuevo;

    else{
        struct nodo*anterior;
        struct nodo*actual;
        anterior=NULL;
        actual=raiz;
        while(actual != NULL){
            anterior=actual;            
            if (numero <actual -> valor)
                actual = actual -> izquierda;
            else
                actual=actual->derecha;
        }    
        if (numero < anterior -> valor)
            anterior -> izquierda = nuevo;
        else
            anterior -> derecha = nuevo;
    }
}

void borrarArbol(struct nodo *elemento){
    if (elemento != NULL){
        printf("Eliminar nodo con el valor %d\n", elemento ->valor);
        borrarArbol(elemento->izquierda);
        borrarArbol(elemento->derecha);
        free(elemento);
    }
}

void recorridoPreorder(struct nodo *inicial){
    if (inicial != NULL){
        printf("%d ", inicial->valor);
        recorridoPreorder(inicial->izquierda);
        recorridoPreorder(inicial->derecha);
    }
}

void recorridoInorder(struct nodo *inicial){
    if (inicial != NULL){
        recorridoInorder(inicial->izquierda);
        printf("%d ", inicial->valor);
        recorridoInorder(inicial->derecha);
    }
}

void recorridoPostorder(struct nodo *inicial){
    if (inicial != NULL){
        recorridoPostorder(inicial->izquierda);
        recorridoPostorder(inicial->derecha);
        printf("%d ", inicial->valor);
    }
}

int contarNodos(struct nodo *inicial, int cont){
    if (inicial != NULL){
        cont++;
        cont = contarNodos(inicial->izquierda, cont);
        cont = contarNodos(inicial->derecha, cont);
    }
    return cont;
}

int sumarArbol(struct nodo *inicial, int sum){
    if (inicial != NULL){
        sum += inicial->valor;
        printf("%d ", inicial->valor);
        printf("-> %D \n", sum);
        sum = sumarArbol(inicial->izquierda, sum);
        sum = sumarArbol(inicial->derecha, sum);
    }
    return sum;
}
