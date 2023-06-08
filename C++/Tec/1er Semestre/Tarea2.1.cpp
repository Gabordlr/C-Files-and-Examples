#include<iostream>
#include<string>
using namespace std;

struct Clientes{
    string nombre;
    int telefono;
    int gasto;
};

void dulceria(int*acumulador){
    int total;
    cout << "Cuanto gastaste en la dulceria?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en la dulceria" << endl;

    (*acumulador) += total;
}

void vinos(int*acumulador){
    int total;
    cout << "Cuanto gastaste en los vinos?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en vinos y licores" << endl;

    (*acumulador) += total;
}

void verdura(int*acumulador){
    int total;
    cout << "Cuanto gastaste en frutas y verduras?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en frutas y verduras" << endl;

    (*acumulador) += total;
}

void limpieza(int*acumulador){
    int total;
    cout << "Cuanto gastaste en articulos de limpieza?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en articulos de limpieza" << endl;

    (*acumulador) += total;
}

void carnes(int*acumulador){
    int total;
    cout << "Cuanto gastaste en carnes?" << endl;
    
    cin>>total;

    cout << "Gracias por gastar " << total << " pesos en carnes y congelados" << endl;

    (*acumulador) += total;
}

void tienda(string *name, int *phone, int *acu){
    cout << "Ingrese su nombre" << endl;
    cin >> *name;

    cout << "Ingrese telefono" << endl;
    cin >> *phone;

    int acumulador = 0;
    dulceria(&acumulador);
    vinos(&acumulador);
    verdura(&acumulador);
    limpieza(&acumulador);
    carnes(&acumulador);

    cout << "En total gastaste " << acumulador << " pesos" << endl;
    cout << "==============" << endl;
    *acu = acumulador;
}

void ventasTotales(Clientes** lista, int size, int *ventas)
{
    for(int i=0; i<size; i++){
        *ventas += lista[i]->gasto;
    }
    (*ventas)--;
    cout << "Las ventas totales son: " << *ventas << "$" << endl;
}

void agregarContacto(Clientes* contacto, Clientes** lista, int* posicion)
{
    lista[*posicion] = contacto;
    (*posicion)++;
}

int buscarNombre(Clientes** lista, int size, string name)
{
    for(int i=0; i<size; i++)
    {
        if (lista[i]->nombre == name)
        {
            cout << "Datos de cliente" << endl;
            cout << lista[i]->nombre << endl;
            cout << lista[i]->telefono << endl;
            cout << lista[i]->gasto << "$" << endl;
            return i;
        }
    }
    return -1;
}

int main(){
    Clientes** listaDeContactos;
    int size_contactos = 100;
    int numero_elementos_agregados = 0;
    listaDeContactos = new Clientes*[size_contactos];

    int acumulador = 0;
    string nombrePersona;
    int cel;
    int gananciasTotales;


    Clientes usuario1;
    tienda(&nombrePersona, &cel, &acumulador);
    usuario1.nombre = nombrePersona;
    usuario1.telefono = cel;
    usuario1.gasto = acumulador;

    Clientes usuario2;
    tienda(&nombrePersona, &cel, &acumulador);
    usuario2.nombre = nombrePersona;
    usuario2.telefono = cel;
    usuario2.gasto = acumulador;

    Clientes usuario3;
    tienda(&nombrePersona, &cel, &acumulador);
    usuario3.nombre = nombrePersona;
    usuario3.telefono = cel;
    usuario3.gasto = acumulador;

    Clientes usuario4;
    tienda(&nombrePersona, &cel, &acumulador);
    usuario4.nombre = nombrePersona;
    usuario4.telefono = cel;
    usuario4.gasto = acumulador;

    
    Clientes usuario5;
    tienda(&nombrePersona, &cel, &acumulador);
    usuario5.nombre = nombrePersona;
    usuario5.telefono = cel;
    usuario5.gasto = acumulador;

    agregarContacto(&usuario1, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&usuario2, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&usuario3, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&usuario4, listaDeContactos, &numero_elementos_agregados);
    agregarContacto(&usuario5, listaDeContactos, &numero_elementos_agregados);

    buscarNombre(listaDeContactos, size_contactos, "Juan");

    ventasTotales(listaDeContactos, numero_elementos_agregados, &gananciasTotales);

    /*
    for (int i=0; i< numero_elementos_agregados; i++)
    {
        delete listaDeContactos[i];
    }
    delete[] listaDeContactos;
    */
}