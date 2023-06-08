#include <stdio.h>
#include <string.h>

void main(){
    char palabra1[23], palabra2[23];

    printf("Ingrese la 1era palabra: ");
    gets(palabra1);
    
    printf("Ingrese la 2da palabra: ");
    gets(palabra2);

    if (strcmp(palabra1,palabra2)==0){
        printf("Las palabras son iguales \n");
    }

    else{
        printf("Las palabras no son iguales \n");
    }
}