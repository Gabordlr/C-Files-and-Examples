#include<iostream>
#include<string>
#include<math.h>

using namespace std;    
    
void primos(int numero, int *m){
    int y;

    y=2;
    while (numero%y != 0){
        y += 1;
        if (numero == y){
            (*m)++;
            
    }}}

int main(){
    int n, *ptr,nuevo_num, numero, largo, contador, m, p;
    ptr=&n;
    numero = 1;
    p=0;

    while (numero <= 100){
        numero++;
        largo=std::to_string(numero).length();
        contador = 1;
        m=0;
        
        while (contador<=largo){
            *ptr = numero%10;
            numero = numero/10;
            nuevo_num = *ptr;
            nuevo_num = nuevo_num*(pow(10, largo-1));
            nuevo_num = nuevo_num + numero;
            numero = nuevo_num;
        
            contador ++;
            primos(nuevo_num, &m);
        }
        if (m==largo){
            p++;
        }
    }
    cout << p << endl;
    }