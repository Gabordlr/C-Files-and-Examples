#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void main(){
    srand (time(NULL));
    int n, sumatoria = 0, k = 0;
    
    printf("Ingrese las dimensiones de la matriz:");
    scanf("%d", &n);

    int matrix[n][n];
    
    for(int i=0;i<n;i++){
        k++;
        for(int j=0;j<n;j++){
            matrix[i][j]=rand()%10;
            printf("%d ", matrix[i][j]);
            if (j>=k){
                sumatoria += matrix[i][j];
            }
        }
        printf("\n");
    } 
    printf("La sumatoria del triangulo superior es %d \n", sumatoria);

}

