#include<iostream>
#include<string>

using namespace std;

struct Contactos {
    string nombre;
    string direccion;
    string telefono;
    string correo;
    string insta;
    string TikTok;
    string ano;
    string relacion;
};

void agregar_contactos(Contacto* contacto, Contacto** lista, int* posicion)
{
    lista[*posicion] = contacto;
    (*posicion)++;
}


int main (){
    Contactos** ListaUsuarios;
    int n;
    ListaUsuarios = new Contactos*[100];

    agregar_contactos();


}