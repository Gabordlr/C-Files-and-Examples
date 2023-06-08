#include<iostream>
#include<string>
#include<vector>

using namespace std;
#pragma once

class Persona{
    protected:
    string nombre;
    int edad;
    string CURP;

    public:
    string leerPersona();
    string escribirPersona();

    string getNombre();
    int getEdad();
    string getCURP();

    void setNombre(string nombreP);
    void setEdad(int edadP);
    void setCURP(string CURPP);

    public:
    Persona();
    Persona(string nombreP, int edadP, string CURPP);   
};

Persona::Persona(){
    nombre = "Nombre";
    edad = 0;
    CURP = "AAAAAAAAAA";
}

Persona::Persona(string nombreP, int edadP, string CURPP){
    nombre = nombreP;
    edad = edadP;
    CURP = CURPP;
}

string Persona::getNombre(){
    return nombre;
}

int Persona::getEdad(){
    return edad;
}

string Persona::getCURP(){
    return CURP;
}

void Persona::setNombre(string nombreP){
    nombre = nombreP;
}

void Persona::setEdad(int edadP){
    edad = edadP;
}

void Persona::setCURP(string CURPP){
    CURP = CURPP;
}

string Persona::escribirPersona(){
    cout << nombre << endl;
    cout << edad << endl;
    cout << CURP << endl;
    return "";
}

string Persona::leerPersona(){
    cout << "nombre:" << endl;
    cin >> nombre;
    cout << "edad:" << endl;
    cin >> edad;
    cout << "CURP:" << endl;
    cin >> CURP;
    return "";
}

