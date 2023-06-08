#include<iostream>
#include<string>
using namespace std;

struct Contacto
{
    string nombre;
    string direccion;
    int telefono;
    string mail;
    string insta;
    string tiktok;
    int ano;
    string relacion;
};

void agregarContacto(Contacto* contacto, Contacto** lista, int* posicion)
{
    lista[*posicion] = contacto;
    (*posicion)++;
}

int buscarNombre(Contacto** lista, int size, string nombre)
{
    for(int i=0; i<size; i++)
    {
        if (lista[i]->nombre == nombre)
        {
            cout << lista[i]->nombre << endl;
            cout << lista[i]->direccion << endl;
            cout << lista[i]->telefono << endl;
            cout << lista[i]->mail << endl;
            cout << lista[i]->insta << endl;
            cout << lista[i]->tiktok << endl;
            cout << lista[i]->ano << endl;
            cout << lista[i]->relacion << endl;
            return i;
        }
    }
    return -1;
}

int buscarNombreCorreo(Contacto** lista, int size, string mail)
{
    for(int i=0; i<size; i++)
    {
        if (lista[i]->mail == mail)
        {
            return i;
        }
    }
    return -1;
}

void modificarContacto(Contacto** lista, int size, string mail, string nuevoMail)
{
    int pos = buscarNombreCorreo(lista, size, mail);
    if (pos != -1)
    {
        lista[pos]->mail = nuevoMail;
        cout << "El nuevo mail es " << lista[pos]->mail << endl; 
    }
    else
    {
        cout << "contacto no encontrado" << endl;
    }
}

int main()
{
    Contacto** listaDeContactos;
    int size_contactos = 100;
    int numero_elementos_agregados = 0;
    listaDeContactos = new Contacto*[size_contactos];

    Contacto pedrito;
    pedrito.nombre = "Pedrito";
    pedrito.mail = "pedrito@itesm.mx";
    pedrito.direccion = "VascoDeQuiroga";
    pedrito.telefono = 557978;
    pedrito.insta = "Pedro_ito";
    pedrito.tiktok = "Ito_pedro";
    pedrito.ano = 2;
    pedrito.relacion = "Amigos";

    Contacto juanito;
    juanito.nombre = "Juanito";
    juanito.mail = "juanito@itesm.mx";
    juanito.direccion = "Interlomas";
    juanito.telefono = 550055;
    juanito.insta = "Juan_ito";
    juanito.tiktok = "Ito_juan";
    juanito.ano = 4;
    juanito.relacion = "Amigo";


    Contacto luisito;
    luisito.nombre = "luisito";
    luisito.mail = "luisito@tec.mx";
    luisito.direccion = "Polanco";
    luisito.telefono = 551234;
    luisito.insta = "Luis_ito";
    luisito.tiktok = "Ito_luis";
    luisito.ano = 9;
    luisito.relacion = "Hermano";

    Contacto gabrielito;
    gabrielito.nombre = "gabrielito";
    gabrielito.mail = "gabrielito@tec.mx";
    gabrielito.direccion = "Las_aguilas";
    gabrielito.telefono = 554321;
    gabrielito.insta = "Gabo_ito";
    gabrielito.tiktok = "Ito_gabo";
    gabrielito.ano = 7;
    gabrielito.relacion = "Primos";

    Contacto marquito;
    marquito.nombre = "marquito";
    marquito.mail = "marquito@tec.mx";
    marquito.direccion = "SantaFe";
    marquito.telefono = 556291;
    marquito.insta = "Marco_ito";
    marquito.tiktok = "Ito_marco";
    marquito.ano = 5;
    marquito.relacion = "Compañeros";

    agregarContacto(&juanito, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&pedrito, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&luisito, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&gabrielito, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&marquito, listaDeContactos, &numero_elementos_agregados);

    buscarNombre(listaDeContactos, size_contactos, "luisito");

    modificarContacto(listaDeContactos, size_contactos, "juanito@itesm.mx", "juanito@tec.mx"); 

    /*
    for (int i=0; i< numero_elementos_agregados; i++)
    {
        delete listaDeContactos[i];
    }
    delete[] listaDeContactos;
    */

}