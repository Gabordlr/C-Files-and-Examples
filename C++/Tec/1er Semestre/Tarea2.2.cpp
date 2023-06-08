#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, *ptr,nuevo_num, numero;
    ptr=&n;

    cout << "Ingrese numero" << endl;
    cin >> numero;

    while (numero>0){
        
        *ptr= numero%10;
        nuevo_num = nuevo_num*10+*ptr;
        numero = numero/10;
    };

    cout << nuevo_num << endl;

}