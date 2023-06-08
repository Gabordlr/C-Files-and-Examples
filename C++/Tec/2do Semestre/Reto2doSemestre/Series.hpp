#include<iostream>
#include<string>
#include "Streams.hpp"

using namespace std;
#pragma once

class Series: public Streams{
    private:
    int numEpisodio;
    string episodio;
    int temporada;

    public:
    int getNumEpisodio();
    string getEpisodio();
    int getTemporada();
    void print();

    public:
    Series();
    Series(int numEpisodiop, string episodiop, int temporadap, int IDp, string nombrePeliculap, int duracionp, string generop, float calificacionp);
};

Series::Series(){
}

Series::Series(int numEpisodiop, string episodiop, int temporadap, int IDp, string nombrePeliculap, int duracionp, string generop, float calificacionp):Streams(IDp, nombrePeliculap, duracionp, generop, calificacionp){
    numEpisodio = numEpisodiop;
    episodio = episodiop;
    temporada = temporadap;
}

int Series::getNumEpisodio(){
    return numEpisodio;
}

string Series::getEpisodio(){
    return episodio;
}

int Series::getTemporada(){
    return temporada;
}

void Series::print(){
    cout << "---------------------" << endl;
    cout << "Serie ID: " << getID() << endl;
    cout << "Serie: " << getNombre() << endl;
    cout << "Duracion: " << getDuracion() << "min" << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << endl;
    cout << "Temporada: " << getTemporada() << endl;
    cout << "Episodio: " << getNumEpisodio() << endl;
    cout << "Titulo: " << getEpisodio() << endl;
    cout << "---------------------" << endl;
    cout << endl;
}

