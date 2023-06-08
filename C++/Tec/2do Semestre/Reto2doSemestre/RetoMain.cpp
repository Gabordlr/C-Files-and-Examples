#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include "Streams.hpp"
#include "Usuario.hpp"

using namespace std;

int Menu(){
    int opcion;
    cout << "" << endl;
    cout << "============================================================================================" << endl;
    cout << "1. Cargar archivo de datos" << endl;
    cout << "2. Mostrar las peliculas en general con una cierta calificación o de un cierto género" << endl;
    cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
    cout << "4. Mostrar las películas con cierta calificacion" << endl;
    cout << "5. Calificar un video" << endl;
    cout << " " << endl;
    cout << "0. Salir" << endl;  
    cout << "============================================================================================" << endl;
    cout << "" << endl;
    cin >> opcion; 
    return opcion;
}


int main(){
    int opcion;
    string nombreArchivo1;
    string nombreArchivo2;
    string nombreUsuario;
    cout << "Bienvenido a la plataforma de streaming" << endl;
    cout << "Ingrese su usuario: ";
    cin >> nombreUsuario;
    Usuario usuario1(nombreUsuario, 1);

    while (opcion != 0){
        opcion = Menu();
        switch (opcion){
            case 1:
                // cout << "Ingrese nombre del archivo" << endl;
                // cin >> nombreArchivo;
                nombreArchivo1 = "series.csv";
                nombreArchivo2 = "peliculas.csv";
                usuario1.insertFile(nombreArchivo1);
                usuario1.insertFile(nombreArchivo2);
                break;

            case 2:
                usuario1.findVideo();
                break;

            case 3:
                usuario1.findSeries();
                break;

            case 4:
                usuario1.findMovie();
                break;
                
            case 5:
                usuario1.findCalififcacion();
                break;
        }
    }
}



