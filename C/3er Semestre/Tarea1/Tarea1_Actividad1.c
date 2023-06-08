#include <stdio.h>

void main(){
    int num, listaNums[5], i;

    printf("Ingrese el 1er numero: ");
    scanf("%d", &num);    
    listaNums[1]=num*2;

    printf("Ingrese el 2do numero: ");
    scanf("%d", &num);
    listaNums[2]=num*2;

    printf("Ingrese el 3er numero: ");
    scanf("%d", &num);
    listaNums[3]=num*2;

    printf("Ingrese el 4to numero: ");
    scanf("%d", &num);
    listaNums[4]=num*2;

    printf("Ingrese el 5to numero: ");
    scanf("%d", &num);
    printf("\n");
    listaNums[5]=num*2;

    for(i=0; i<5; i++)
        printf("%d ", listaNums[i+1]);

    printf("\n");
}