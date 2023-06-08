#include<iostream>
#include<string>
#include<vector>
#include "Animal.hpp"
#include "Gato.hpp"
#include "Perro.hpp"

using namespace std;

int menu(){
    int opcion;
    cout << "------------------------------------" << endl;
    cout << "1. Mostrar perros" << endl;
    cout << "2. Mostrar gatos" << endl;
    cout << "3. Mostrar todos" << endl;
    cout << "4. Mostrar animales de cierta edad" << endl;
    cout << "5. Ladrar" << endl;
    cout << endl;
    cout << "0. Salir" << endl;
    cout << "------------------------------------" << endl;

    cin>>opcion;
    return opcion;
}

int main(){
    vector<Animal*> animales;
    int opcion=1;

    Gato gato1("Vigotes", "Gato", 2, "Miau", "");
    Gato gato2("Pelusa", "Gato", 3, "MiAO", "");
    Perro perro1("Toby", "Perro", 1, "Woof", "Pitbull");
    Perro perro2("Thor", "Perro", 2, "Guau", "Pastor");

    animales.push_back(&gato1);
    animales.push_back(&gato2);
    animales.push_back(&perro1);
    animales.push_back(&perro2);

    vector<Animal*>::iterator it;

    cout << endl;
    cout << "Bienvenidos a la tienda de animales" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;

    while (opcion!=0){
        opcion = menu();
        switch (opcion){
            case 1:
                for (it = animales.begin(); it != animales.end(); it++){
                    if ((*it)->getEspecie() == "Perro"){
                            (*it)->print();
                        }
                }
                break;
            case 2:
                for (it = animales.begin(); it != animales.end(); it++){
                    if ((*it)->getEspecie() == "Gato"){
                            (*it)->print();
                        }
                }
                break;
            case 3:
                for (it = animales.begin(); it != animales.end(); it++){
                    (*it)->print();
                }
                break;
            case 4:
                int edad;
                cout << "Introduzca la edad maxima: ";
                cin >> edad;
                for (it = animales.begin(); it != animales.end(); it++){
                    if ((*it)->getEdad() <= edad){
                            (*it)->print();
                    }
                }
                break;
            case 5:
                for (it = animales.begin(); it != animales.end(); it++){
                    (*it)->hablar();
                }
                break;
            case 0:

                break;

            default:
                cout << "Opcion no valida" << endl;
}                  
}}