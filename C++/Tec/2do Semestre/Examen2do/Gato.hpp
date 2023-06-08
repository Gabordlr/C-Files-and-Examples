#include<iostream>
#include<string>
#include<vector>
#include "Animal.hpp"

using namespace std;
#pragma once

class Gato: public Animal{
    private:
    string maullido;
    string pelaje;

    public:
    void hablar();
    void print();

    public:
    Gato();
    Gato(string nombreP, string especieP, int edadP, string maullidoP, string pelajeP);
};

Gato::Gato(){}
Gato::Gato(string nombreP, string especieP, int edadP, string maullidoP, string pelajeP): Animal(nombreP, especieP, edadP){
    maullido = maullidoP;
    pelaje = pelajeP;
}

void Gato::hablar(){
    cout << maullido << endl;
    return ;
}

void Gato::print(){
    cout << "------------------------------------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Especie: " << especie << endl;
    cout << "Edad: " << edad << endl;
    cout << "Maullido: " << maullido << endl;
    cout << "------------------------------------" << endl;
}
