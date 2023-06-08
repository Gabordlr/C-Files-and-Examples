#include<iostream>
#include<string>

using namespace std;
#pragma once

class Streams{
    protected:
    int ID;
    string nombrePelicula;
    int duracion;
    string genero;
    float calificacion;

    public:
    int getID();
    string getNombre();
    int getDuracion();
    string getGenero();
    float getCalificacion();
    virtual void print() = 0;

    float setCalififcacion();

    public:
    Streams();
    Streams(int IDp, string nombrePeliculap, int duracionp, string generop, float calificacionp);
};

Streams::Streams(){
}

Streams::Streams(int IDp, string nombrePeliculap, int duracionp, string generop, float calificacionp){
    ID = IDp;
    nombrePelicula = nombrePeliculap;
    duracion = duracionp;
    genero = generop;
    calificacion = calificacionp;
}

int Streams::getID(){
    return ID;
}

string Streams::getNombre(){
    return nombrePelicula;
}

int Streams::getDuracion(){
    return duracion;
}

string Streams::getGenero(){
    return genero;
}

float Streams::getCalificacion(){
    return calificacion;
}

float Streams::setCalififcacion(){
    float calificacionp;
    cout << "Ingrese la calificacion: ";
    cin >> calificacionp;
    calificacion = calificacionp;
    return 0;
}
