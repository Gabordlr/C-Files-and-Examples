#include<stdio.h>
#include<stdlib.h>

#define capacidad 10

struct hash{
    int valor;
    int llave;
};

struct hash *tabla;
int longitud = 0;

void inicializarHash();
void insertar(int llave, int valor);
void mostrar();
void eliminarHash();
void eliminar(int llave);
int codigoHash(int llave);

int main()
{
    inicializarHash();
    printf("\e[1;34mUso de una tabla hash\n\n\e[0m");
    printf("\033[1;30mOperaciones \"insercion\"\n\e[0m");
    insertar(1, 100);
    insertar(3, 101);
    insertar(2, 200);
    insertar(114, 201);
    printf("\n");
    printf("\e[1;30mOperacion \"mostrar elementos\"\n\e[0m");
    mostrar();
    printf("\n");
    printf("\e[1;30mOperaciones \"eliminacion\"\n\e[0m");
    eliminar(100);
    eliminar(3);
    printf("\n");
    printf("\e[1;30mOperacion \"mostrar elementos\"\n\e[0m");
    mostrar();
    eliminarHash();
}

void inicializarHash()
{
    int x;
    printf("Se inicializa la tabla hash con %d espacios disponibles", capacidad);
    tabla = malloc(sizeof(struct hash) * capacidad);
    for (x=0;x<capacidad;x++){
        tabla[x].llave = 0;
        tabla[x].valor = 0;
    }
}

int codigoHash(int llave)
{
    return(llave%capacidad);
}

void insertar(int llave, int valor)
{
    int indice = codigoHash(llave);

    if(tabla[indice].valor == 0){
        tabla[indice].llave = llave;
        tabla[indice].valor = valor;
        longitud++;
        printf("En la llave \'%d\' se inserta el valor  \'%d\' \n", llave, valor);
    }

    else if(tabla[indice].llave==llave){
        printf("La llave \'%d\' ya exisita por lo que se actualizo su valor a \'%d\' \n", llave, valor);
        tabla[indice].valor = valor;
    }

    else{
        printf("El elemento no se pudo insertar en la tabla hash \n");
    }
}

void eliminar(int llave)
{
    int indice = codigoHash(llave);
    if(tabla[indice].valor == 0){
        printf("El elemento que sea eliminar no existe");
    }

    else{
        printf("Se elimina la llave \'%d\' y el valor \'%d\' de la tabla \n", llave, tabla[indice].valor);
        tabla[indice].llave=0;
        tabla[indice].valor=0;
        longitud--;
    }
}

void mostrar()
{
    int x;
    printf("Elementos de la tabla hash\n");

    for(x=0;x<capacidad;x++){
        if(tabla[x].valor != 0)
            printf("Posicion[%d]: llave \'%d\', valor \'%d\' \n", x+1, tabla[x].llave, tabla[x].valor);
    }
}

void eliminarHash()
{
    free(tabla);
    return;
}