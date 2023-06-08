#include<iostream>
#include<string>
#include<vector>
#include "Streams.hpp"
#include "Series.hpp"
#include "Peliculas.hpp"

using namespace std;
#pragma once

class Usuario{
    private:
    string nombreUser;
    int ID_Usuario;
    vector<Peliculas> lista_streams_peli;
    vector<Series> lista_streams_seri;
    vector<Peliculas>::iterator it1;
    vector<Series>::iterator it2;

    public:
    string getNombreUser();
    int getID_Usuario();
    int insertFile(string nombreArchivo);
    string findCalififcacion();
    string findSeries();
    string findMovie();
    string findVideo();
    
    public:
    Usuario();
    Usuario(string nombrep, int ID_Usuariop);
    
};

Usuario::Usuario(){
}

Usuario::Usuario(string nombreUserp, int ID_Usuariop){
    nombreUser = nombreUserp;
    ID_Usuario = ID_Usuariop;
}

string operator >>(istream& CIN, string& valor){
    cin.ignore();
    getline(cin, valor, '\n');
    return "";
}

string Usuario::getNombreUser(){
    return nombreUser;
}

int Usuario::getID_Usuario(){
    return ID_Usuario;
}

int Usuario::insertFile(string nombreArchivo){
    vector<vector<string> > contenido;
	vector<string> row;
	string line, word;
    int count = 0;

	fstream file (nombreArchivo, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			contenido.push_back(row);
		}
	}

    if (contenido[0].size() == 5){
        vector<vector<string> > ::iterator it;
        for (it = contenido.begin()+1; it != contenido.end(); ++it){
            int IDx = stoi((*it)[0]);
            int duracionx = stoi((*it)[2]);
            float calificacionx  = std::stod((*it)[4]);
            Peliculas p1(IDx, (*it)[1], duracionx, (*it)[3], calificacionx);
            lista_streams_peli.push_back(p1);
        }
        cout << "PELICULAS===>" << lista_streams_peli.size() << endl;
        return 0;
    }

    else if (contenido[0].size() == 8){
        vector<vector<string> > ::iterator it;
        for (it = contenido.begin()+1; it != contenido.end(); ++it){
            int numEpisodiox = stoi((*it)[2]);
            int IDx = stoi((*it)[0]);
            int temporadax = stoi((*it)[4]);
            int duracionx = stoi((*it)[5]);
            float calificacionx  = std::stod((*it)[7]);
            Series s1(numEpisodiox, (*it)[3], temporadax, IDx, (*it)[1], duracionx, (*it)[6], calificacionx);
            lista_streams_seri.push_back(s1);
        }
        cout << "SERIES===>" << lista_streams_seri.size() << endl;
        return 0;
    }
}

string Usuario::findVideo(){
    bool count = false;
    string gene=" ";
    float cali;
    int64_t opcion;
    cout << "=================" << endl;
    cout<<"1. Calificación"<<endl;
    cout<<"2. Genero"<<endl;
    cout<<endl;
    cout<<"0. Volver" <<endl;
    cout << "=================" << endl;
    cin>>opcion;
    if (opcion == 1){
        cout<<"Ingrese calififcacion: ";
        cin>>cali;
        cout << "---------------------" << endl;
        cout << endl;
        for (it1 = lista_streams_peli.begin(); it1 != lista_streams_peli.end(); it1++){
            if (it1->getCalificacion() == cali){
                it1->print();
                count=true;
            }
        }
        for (it2 = lista_streams_seri.begin(); it2 != lista_streams_seri.end(); it2++){
            if (it2->getCalificacion() == cali){
                it2->print();
                count=true;
            }
        }
        if (count == false){
            cout<<"No se encontraron videos"<<endl;
        }
        return "";
    }
    else if (opcion == 2){
        cout<<"Ingrese genero: ";
        cin>>gene;
        cout << "---------------------" << endl;
        cout << endl;
        for (it1 = lista_streams_peli.begin(); it1 != lista_streams_peli.end(); it1++){
            if (it1->getGenero() == gene){
                it1->print();
                count=true;
            }
        }
        for (it2 = lista_streams_seri.begin(); it2 != lista_streams_seri.end(); it2++){
            if (it2->getGenero() == gene){
                it2->print();
                count=true;
            }
        }
        if (count == false){
            cout<<"No se encontraron videos"<<endl;
        }
    }
    else if (opcion == 0){
        return "";

    }
    else {
        cout<<"Opcion no valida"<<endl;
    }
    return "";
} 

string Usuario::findSeries(){
    bool count = false;
    string serie=""; 
    float calif;
    cout<<"Ingrese serie: ";
    cin>>serie;
    cout<<"Ingrese calififcacion: ";
    cin>>calif;
    for (it2 = lista_streams_seri.begin(); it2 != lista_streams_seri.end(); it2++){
        if (it2->getNombre() == serie && it2->getCalificacion() == calif){
            it2->print();
            count=true;
        }
    }
    if (count==false){
        cout << "No se encontro la serie" << endl;
    }
    return "";
}

string Usuario::findMovie(){
    int count = false;
    float cali;
    cout<<"Ingrese calififcacion: ";
    cin>>cali;
    for (it1 = lista_streams_peli.begin(); it1 != lista_streams_peli.end(); it1++){
        if (it1->getCalificacion() == cali){
                it1->print();
                count=true;
        }
    }
    if (count == false){
        cout << "No se encontro la pelicula" << endl;
    }
    return "";
}

string Usuario::findCalififcacion(){
    bool count = false;
    string nombre;
    cout<<"Ingrese nombre de video: ";
    cin>>nombre;
    for (it1 = lista_streams_peli.begin(); it1 != lista_streams_peli.end(); it1++){
        if (it1->getNombre() == nombre){
            it1->setCalififcacion();
            count=true;
        }
    }
    for (it2 = lista_streams_seri.begin(); it2 != lista_streams_seri.end(); it2++){
        if (it2->getEpisodio() == nombre){
            it2->setCalififcacion();
            count=true;
        }
    }
    if (count == false){
        cout << "No se encontro el video" << endl;
    }
    return "";
}