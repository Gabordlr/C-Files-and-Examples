
#include<iostream>
#include<string>
#include "Streams.hpp"

using namespace std;
#pragma once

class Peliculas: public Streams{
    public:
    void print();
      
    public:
    Peliculas();
    Peliculas(int IDp, string nombrePeliculap, int duracionp, string generop, float calificacionp);
};

Peliculas::Peliculas(){
}

Peliculas::Peliculas(int IDp, string nombrePeliculap, int duracionp, string generop, float calificacionp):Streams(IDp, nombrePeliculap, duracionp, generop, calificacionp){
}

void Peliculas::print(){
    cout << "---------------------" << endl;
    cout << "Pelicula ID: " << getID() << endl;
    cout << "Pelicula: " << getNombre() << endl;
    cout << "Duracion: " << getDuracion() << "min" << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << endl;
    cout << "---------------------" << endl;
    cout << endl;
}

