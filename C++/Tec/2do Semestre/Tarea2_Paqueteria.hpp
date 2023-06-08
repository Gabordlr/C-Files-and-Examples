#ifndef TAREA2_HERENCIA_CLASES_HPP_INCLUDED
#define TAREA2_HERENCIA_CLASES_HPP_INCLUDED

#include<iostream>
#include<string>

using namespace std;

//ENVIOOOOOOOO
class Envio{
    private:
    string Dnombre;
    string Ddireccion;
    string Destado;
    string Dciudad;
    int DcodigoPostal;

    string Rnombre;
    string Rdireccion;
    string Restado;
    string Rciudad;
    int RcodigoPostal;

    protected:
    int costoInicial=5;
    
    public:
    virtual double calcularCosto()=0;

    string getDnombre();
    string getDdireccion();
    string getDestado();
    string getDciudad();
    int getDcodigoPostal();
    string direccionCompletaD();

    string getRnombre();
    string getRdireccion();
    string getRestado();
    string getRciudad();
    int getRcodigoPostal();
    string direccionCompletaR();

    public:
    Envio();
    Envio(string Dnombrep, string Ddireccionp, string Destadop, string Dciudadp, int DcodigoPostalp, string Rnombrep, string Rdireccionp, string Restadop, string Rciudadp, int RcodigoPostalp);
};

Envio::Envio(){
}

Envio::Envio(string Dnombrep, string Ddireccionp, string Destadop, string Dciudadp, int DcodigoPostalp, string Rnombrep, string Rdireccionp, string Restadop, string Rciudadp, int RcodigoPostalp){
    Dnombre = Dnombrep;
    Ddireccion = Ddireccionp;
    Destado = Destadop;
    Dciudad = Dciudadp;
    DcodigoPostal = DcodigoPostalp;

    Rnombre = Rnombrep;
    Rdireccion = Rdireccionp;
    Restado = Restadop;
    Rciudad = Rciudadp;
    RcodigoPostal = RcodigoPostalp;
}

string Envio::getDnombre(){
    return Dnombre;
}
string Envio::getDdireccion(){
    return Ddireccion;
}
string Envio::getDestado(){
    return Destado;
}
string Envio::getDciudad(){
    return Dciudad;
}
int Envio::getDcodigoPostal(){
    return DcodigoPostal;
}
string Envio::direccionCompletaD(){
    return Ddireccion + ", " + Destado + ", " + Dciudad + ", " + to_string(DcodigoPostal);
}

string Envio::getRnombre(){
    return Rnombre;
}
string Envio::getRdireccion(){
    return Rdireccion;
}
string Envio::getRestado(){
    return Restado;
}
string Envio::getRciudad(){
    return Rciudad;
}
int Envio::getRcodigoPostal(){
    return RcodigoPostal;
}
string Envio::direccionCompletaR(){
    return Rdireccion + ", " + Restado + ", " + Rciudad + ", " + to_string(RcodigoPostal);
}

//PAQUETEEEE
class Paquete: public Envio{
    private:
    float profundidad;
    float alto;
    float largo;
    float peso;
    double precioPorKilo;

    public:
    double calcularCosto();

    public:
    Paquete();
    Paquete(float profundidadp, float altop, float largop, float pesop, double precioPorKilop, string Dnombrep, string Ddireccionp, string Destadop, string Dciudadp, int DcodigoPostalp, string Rnombrep, string Rdireccionp, string Restadop, string Rciudadp, int RcodigoPostalp);
};

Paquete::Paquete(){}
Paquete::Paquete(float profundidadp, float altop, float largop, float pesop, double precioPorKilop, string Dnombrep, string Ddireccionp, string Destadop, string Dciudadp, int DcodigoPostalp, string Rnombrep, string Rdireccionp, string Restadop, string Rciudadp, int RcodigoPostalp):Envio(Dnombrep, Ddireccionp, Destadop, Dciudadp, DcodigoPostalp, Rnombrep, Rdireccionp, Restadop, Rciudadp, RcodigoPostalp){
    profundidad = profundidadp;
    alto = altop;
    largo = largop;
    peso = pesop;
    precioPorKilo = precioPorKilop;
}

double Paquete::calcularCosto(){ 
    return (peso * precioPorKilo) + costoInicial;
}


//CARTAAAAA
class Carta: public Envio{
    private:
    int largo;
    int ancho;
    int cargoAdicional=3;

    public:
    double calcularCosto();

    public:
    Carta();
    Carta(int largop, int anchop, string Dnombrep, string Ddireccionp, string Destadop, string Dciudadp, int DcodigoPostalp, string Rnombrep, string Rdireccionp, string Restadop, string Rciudadp, int RcodigoPostalp);
};

Carta::Carta(){}
Carta::Carta(int largop, int anchop, string Dnombrep, string Ddireccionp, string Destadop, string Dciudadp, int DcodigoPostalp, string Rnombrep, string Rdireccionp, string Restadop, string Rciudadp, int RcodigoPostalp):Envio(Dnombrep, Ddireccionp, Destadop, Dciudadp, DcodigoPostalp, Rnombrep, Rdireccionp, Restadop, Rciudadp, RcodigoPostalp){
    largo = largop;
    ancho = anchop;
}

double Carta::calcularCosto(){
   if ((largo > 30) || (ancho > 25)){
        return costoInicial + cargoAdicional;
    }
    else {
        return costoInicial;
   }
}

#endif
  