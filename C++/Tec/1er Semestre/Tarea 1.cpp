#include <iostream>

using namespace std;


void contar_primos(){

    int numero, y, m;

    numero=1;
    m=0;

    cout << "La cantidad de primos es " << endl;

    while (numero <= 10000000){
    y=2;
    numero += 1;
        while (numero%y != 0){
            y += 1;
            if (numero == y) {
                m += 1;
        }
    }}
    cout << m << endl;
}

void viciesto(){
    int año;
    bool verificador;

    cout << "Ingrese un año " << endl;

    cin >> año;

    if (año%4 == 0 && año%100 != 0){
        cout << año << " si es un año viciesto" << endl; 
    }

    else if (año%400 == 0){
        cout << año << " si es un año viciesto" << endl;
    }

    else {
        cout << año << " no es un año viciesto" << endl;
    }
}

void print_primos(){
    int numero, y;

    numero=1000;
    
    cout << "Los numeros primos son:" << endl;

    while (numero <= 100000){
    y=2;
    numero += 1;
        while (numero%y != 0){
            y += 1;
            if (numero == y){
                cout << " " << numero;
            }
        }}
    cout << endl;
}

void naturales(){
    int numero, y, suma;

    cout << "Ingrese numero" << endl;
    cin >> numero;
    suma = 0;
    y = 0;

    while (numero != y){
        y += 1;
        if (numero%y == 0){
            suma += y;
    }}
    suma -= numero;

    if (numero==suma){
        cout << numero << " si es un natural perfecto" << endl;
    }

    else{
        cout << numero << " no es un natural perfecto" << endl;
    }
}

void multiplos(){
    int y, sum;

    sum = 0;
    y = 1000;

    while (y != 0){
        y -= 1;
        if (y%3 == 0){
            sum += y;
    }
        else if (y%5 == 0){
            sum += y;
    }}
    cout << "La suma total es " << sum << endl;
}

void digitos(){
    string numero;
    
    cout << "Ingrese un numero" << endl;
    cin >> numero;

for (int i=0; i < numero.size(); ++i) {
    cout << "Posición: " << i+1 << "; Valor: " << numero[i] << endl;
}
}

int main(){
    viciesto();
    print_primos();
    naturales();
    contar_primos();
    multiplos();
    digitos();
}