#include<iostream>
#include<string>
#include<vector>

using namespace std;
#pragma once

class Animal{
    protected:
    string nombre;
    string especie;
    int edad;

    public:
    string getEspecie();
    int getEdad();
    virtual void hablar()=0;
    virtual void print()=0;

    public:
    Animal();
    Animal(string nombreP, string especieP, int edadP);
};

Animal::Animal(){}

Animal::Animal(string nombreP, string especieP, int edadP){
    nombre = nombreP;
    especie = especieP;
    edad = edadP;
}

string Animal::getEspecie(){
    return especie;
}

int Animal::getEdad(){
    return edad;
}
