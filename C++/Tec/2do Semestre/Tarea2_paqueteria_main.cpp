#include<iostream>
#include<string>
#include<vector>
#include "Tarea2_Paqueteria.hpp"

using namespace std;

int main(){
    int costoTotal=0;
    Paquete paquete1(3.5, 5, 5, 6, 2, "Juan", "Calle falsa 123", "CDMX", "CDMX", 12345, "Pedro", "Calle verdadera 321", "CDMX", "CDMX", 3000);
    Paquete paquete2(2,4,7,4,5,"Diego", "Reforma", "CDMX", "Mexico", 10101, "Julio", "Av. las palmas", "Argentina", "Buenos Aires", 90111);
    Carta carta1(32,25, "Luis", "Alvaro Obregon", "Sao Pablo", "Brasil", 12345, "Maria", "Vasco de Quiroga", "CDMX", "CDMX", 2030);
   
   vector<Envio*> lista_Envio;
   lista_Envio.push_back(&paquete1);
   lista_Envio.push_back(&paquete2);
   lista_Envio.push_back(&carta1);

   vector<Envio*>::iterator it;
   for(it = lista_Envio.begin(); it != lista_Envio.end(); it++){
       costoTotal += (*it)->calcularCosto();
       cout << "=====================" << endl;
       cout << "De: " << (*it)->getDnombre() << endl;
       cout << "Para: " << (*it)->getRnombre() << endl;
       cout << "Proviene de: " << (*it)->direccionCompletaD() << endl;
       cout << "Destino: " << (*it)->direccionCompletaR() << endl;
       cout << "El precio del envio es: " << (*it)->calcularCosto() << " USD" << endl;
       cout << "=====================" << endl;
    }
    cout << "El costo total de los envios es: " << costoTotal << " USD" << endl;
}


