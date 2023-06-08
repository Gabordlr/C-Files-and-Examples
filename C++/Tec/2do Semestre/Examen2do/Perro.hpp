#include<iostream>
#include<string>
#include<vector>
#include "Animal.hpp"

using namespace std;
#pragma once

class Perro: public Animal{
    private:
    string ladrido;
    string raza;

    public:
    void hablar();
    void print();

    public:
    Perro();
    Perro(string nombreP, string especieP, int edadP, string ladridoP, string razaP);
};

Perro::Perro(){}
Perro::Perro(string nombreP, string especieP, int edadP, string ladridoP, string razaP): Animal(nombreP, especieP, edadP){
    ladrido = ladridoP;
    raza = razaP;
}

void Perro::hablar(){
    cout << ladrido << endl;
    return;
}

void Perro::print(){
    cout << "------------------------------------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Especie: " << especie << endl;
    cout << "Edad: " << edad << endl;
    cout << "Raza: " << raza << endl;
    cout << "------------------------------------" << endl;
}