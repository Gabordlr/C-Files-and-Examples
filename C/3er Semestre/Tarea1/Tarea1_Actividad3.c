#include <stdio.h>

int main(){
    char str[50];
    char *str_infinite;

    printf("Cadena de texto: \n");
    scanf("%s", str);

    for(int i=0;i<strlen(str); i++)
        printf("%c\n", str[i]);

    printf("Numero de caracteres: %i\n", strlen(str));
}