#include<iostream>
#include<string>
#include<vector>
#include "PersonaMax.hpp"

using namespace std;
#pragma once

class Puesto: public Persona{
    protected:
    string puesto;

    public:
    string leerPuesto();
    string escribirPuesto();

    string getPuesto();
    void setPuesto(string puesto);

    public:
    Puesto();
    Puesto(string puesto, string nombreP, int edadP, string CURPP);
};

Puesto::Puesto(){}

Puesto::Puesto(string puestoP, string nombreP, int edadP, string CURPP):Persona(nombreP, edadP, CURPP){
    puesto = puestoP;
    nombre = nombreP;
    edad = edadP;
    CURP = CURPP;
}