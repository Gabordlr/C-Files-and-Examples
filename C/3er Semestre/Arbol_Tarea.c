#include <stdio.h>
#include <stdlib.h>

struct cola{
    struct nodo *valor;
    struct cola *siguiente;
};

struct cola *frente = NULL;
struct cola *atras = NULL;

int colaVacia();
void queue(struct nodo *numero);
void dequeue();
void mostrarElementosCola();

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
int sumarArbolPar(struct nodo *inicial, int sum);
int sumarArbolImpar(struct nodo *inicial, int sum);
void imprimirHojas(struct nodo *inicial);
void recorridoAnchura(struct nodo *inicial);

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
    printf("La suma del arbol par es = %d", sumarArbolPar(raiz,0));
    printf("\n\n");
    printf("La suma del arbol impar es = %d", sumarArbolImpar(raiz,0));
    printf("\n\n");
    printf("Los nodos hoja son:\n");
    imprimirHojas(raiz);
    printf("\n\n");
    printf("Operaciones \"recorrido anchura\"\n");
    recorridoAnchura(raiz);
    printf("\n\n");
    printf("Operaciones \"eliminar\"\n");
    borrarArbol(raiz);
}

int colaVacia(){
    if (frente == NULL) //-->  O(2)
        return 1;
    else
        return 0;
}//-->  O(2)E -> O(1)G

void queue(struct nodo *numero){
    struct cola *elemento = malloc(sizeof(struct cola)); //-->  O(1)
    if (elemento == NULL){ //-->  O(2)
        printf("No se pueden crear elementos en la cola");
    }
    elemento->valor=numero; //-->  O(1)
    elemento->siguiente=NULL; //-->  O(1)
    if (colaVacia() == 1){ //-->  O(3) + O(1)
        frente = elemento;
        atras = elemento;
    }
    else{
        atras->siguiente = elemento;
        atras = elemento;
    }
}//-->  O(9)E -> O(1)G

void dequeue(){
    if (colaVacia==1){ //-->  O(1)
        printf("La cola esta vacia\n");
        return;
    }
    else{ //-->  O(7)
        struct cola *temporal; //-->  O(1)
        temporal = frente; //-->  O(1)
        if (frente == atras){ //-->  O(3)
            frente = NULL;
            atras = NULL;
        }
        else
            frente=frente->siguiente;
        printf("Eliminando de la cola: %d\n", temporal->valor); //-->  O(1)
        free(temporal); //-->  O(1)
    }
}//-->  O(8)E -> O(1)G

void mostrarElementosCola(){
    int i=0; //-->  O(1)
    struct cola *temporal; //-->  O(1)
    temporal = frente; //-->  O(1)
    printf("Elementos en la cola:\n"); //-->  O(1)
    while (temporal != NULL){ //-->  O(3n)
        printf("Elemento[%d] = %d\n", i, temporal->valor); //-->  O(1)
        temporal = temporal -> siguiente; //-->  O(1)
        i++; //-->  O(1)
    }
}//-->  O(3n+4)E -> O(n)G

void insertarNodo(int numero){
    struct nodo *nuevo = malloc(sizeof(struct nodo)); //-->  O(1)
    nuevo->valor=numero; //-->  O(1)
    nuevo -> izquierda=NULL; //-->  O(1)
    nuevo->derecha=NULL; //-->  O(1)
    printf("Se inserta el nodo con el valor %d en el arbol binario \n", numero); //-->  O(1)

    if (raiz == NULL)
        raiz=nuevo;

    else{ //-->  O(9n+4)
        struct nodo*anterior; //-->  O(1)
        struct nodo*actual; //-->  O(1)
        anterior=NULL; //-->  O(1)
        actual=raiz; //-->  O(1)
        while(actual != NULL){ //-->  O(9n)
            anterior=actual; //-->  O(1)
            if (numero <actual -> valor) //-->  O(2)
                actual = actual -> izquierda; 
            else //-->  O(2)
                actual=actual->derecha;
        }    
        if (numero < anterior -> valor) //-->  O(2)
            anterior -> izquierda = nuevo;
        else //-->  O(2)
            anterior -> derecha = nuevo; 
    }
}//-->  O(9n+9)E -> O(n)G

void borrarArbol(struct nodo *elemento){ //-->  O(n)
    if (elemento != NULL){
        printf("Eliminar nodo con el valor %d\n", elemento ->valor);
        borrarArbol(elemento->izquierda);
        borrarArbol(elemento->derecha);
        free(elemento);
    }
}

void recorridoPreorder(struct nodo *inicial){ //-->  O(n)
    if (inicial != NULL){
        printf("%d ", inicial->valor);
        recorridoPreorder(inicial->izquierda);
        recorridoPreorder(inicial->derecha);
    }
}

void recorridoInorder(struct nodo *inicial){ //-->  O(n)
    if (inicial != NULL){
        recorridoInorder(inicial->izquierda);
        printf("%d ", inicial->valor);
        recorridoInorder(inicial->derecha);
    }
}

void recorridoPostorder(struct nodo *inicial){ //-->  O(n)
    if (inicial != NULL){
        recorridoPostorder(inicial->izquierda);
        recorridoPostorder(inicial->derecha);
        printf("%d ", inicial->valor);
    }
}

int contarNodos(struct nodo *inicial, int cont){ //-->  O(n)
    if (inicial != NULL){
        cont++;
        cont = contarNodos(inicial->izquierda, cont);
        cont = contarNodos(inicial->derecha, cont);
    }
    return cont;
}

int sumarArbolPar(struct nodo *inicial, int sum){ //-->  O(n)
    if (inicial != NULL){
        if (inicial->valor%2==0)
            sum += inicial->valor;
        sum = sumarArbolPar(inicial->izquierda, sum);
        sum = sumarArbolPar(inicial->derecha, sum);
    }
    return sum;
}

int sumarArbolImpar(struct nodo *inicial, int sum){ //-->  O(n)
    if (inicial != NULL){
        if (inicial->valor%2==1)
            sum += inicial->valor;
        sum = sumarArbolImpar(inicial->izquierda, sum);
        sum = sumarArbolImpar(inicial->derecha, sum);
    }
    return sum;
}

void imprimirHojas(struct nodo *inicial){ //-->  O(n)
    if (inicial != NULL){
        if(inicial->derecha==NULL && inicial->izquierda==NULL)
            printf("%d ", inicial->valor);
        imprimirHojas(inicial->izquierda);
        imprimirHojas(inicial->derecha);
    }
}

void recorridoAnchura(struct nodo *inicial){ 
    printf("%d ", inicial->valor); //-->  O(1)
    queue(inicial->izquierda); //-->  O(1)
    queue(inicial->derecha); //-->  O(1)

    struct cola *temporal; //-->  O(1)
    temporal = frente; //-->  O(1)
    while (temporal != NULL){ //-->  O(6n)
        printf("%d ", temporal->valor->valor); //-->  O(1)
        if (temporal->valor->izquierda != NULL) //-->  O(2)
            queue(temporal->valor->izquierda);
        if (temporal->valor->derecha != NULL) //-->  O(2)
            queue(temporal->valor->derecha);
        temporal = temporal -> siguiente; //-->  O(1)
    }
}//-->  O(6n+5)E -> O(n)G
