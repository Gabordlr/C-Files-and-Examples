#include <iostream>
using namespace std;

void dulceria(int*acumulador){
    int total;
    cout << "Cuanto gastaste en la dulceria?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en la dulceria" << endl;

    (*acumulador) += total;
}

void vinos(int*acumulador){
    int total;
    cout << "Cuanto gastaste en los vinos?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en vinos y licores" << endl;

    (*acumulador) += total;
}

void verdura(int*acumulador){
    int total;
    cout << "Cuanto gastaste en frutas y verduras?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en frutas y verduras" << endl;

    (*acumulador) += total;
}

void limpieza(int*acumulador){
    int total;
    cout << "Cuanto gastaste en articulos de limpieza?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en articulos de limpieza" << endl;

    (*acumulador) += total;
}

void carnes(int*acumulador){
    int total;
    cout << "Cuanto gastaste en carnes?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en carnes y congelados" << endl;

    (*acumulador) += total;
}

int main(){
    int acumulador = 0;
    dulceria(&acumulador);
    vinos(&acumulador);
    verdura(&acumulador);
    limpieza(&acumulador);
    carnes(&acumulador);

    cout << "En total gastaste " << acumulador << " pesos" << endl;
}