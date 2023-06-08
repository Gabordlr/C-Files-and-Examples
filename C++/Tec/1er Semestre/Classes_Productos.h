#include<iostream>
#include<string>

using namespace std;


//CAFEEEE #1
class Cafe{
    private:
    string nombre;
    string tipo;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getNombre();
    string getTipo();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirCafe();

    public:
    Cafe();
    Cafe(string nombreP, string tipoP, int precioP, int tamanioP, int caloriasP);
};

Cafe::Cafe(){}
Cafe::Cafe(string nombreP, string tipoP, int precioP, int tamanioP, int caloriasP)
{
    nombre = nombreP;
    tipo = tipoP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Cafe::getNombre()
{
    return nombre;
}

string Cafe::getTipo()
{
    return tipo;
}

int Cafe::getPrecio()
{
    return precio;
}

int Cafe::getTamanio()
{
    return tamanio;
}

int Cafe::getCalorias()
{
    return calorias;
}

void Cafe::imprimirCafe(){
    cout << "nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//JUGOOOO #2
class Jugo{
    private:
    string nombre;
    string fruta;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getNombre();
    string getFruta();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirJugo();

    public:
    Jugo(

    );
    Jugo(string nombreP, string frutaP, int precioP, int tamanioP, int caloriasP);
};

Jugo::Jugo(){}
Jugo::Jugo(string nombreP, string frutaP, int precioP, int tamanioP, int caloriasP)
{
    nombre = nombreP;
    fruta = frutaP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Jugo::getNombre()
{
    return nombre;
}

string Jugo::getFruta()
{
    return fruta;
}

int Jugo::getPrecio()
{
    return precio;
}

int Jugo::getTamanio()
{
    return tamanio;
}

int Jugo::getCalorias()
{
    return calorias;
}

void Jugo::imprimirJugo(){
    cout << "nombre: " << nombre << endl;
    cout << "Fruta: " << fruta << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//REFRESCOOOOO #3
class Refresco{
    private:
    string nombre;
    string sabor;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getNombre();
    string getSabor();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirRefresco();

    public:
    Refresco();
    Refresco(string nombreP, string saborP, int precioP, int tamanioP, int caloriasP);
};

Refresco::Refresco(){}
Refresco::Refresco(string nombreP, string saborP, int precioP, int tamanioP, int caloriasP)
{
    nombre = nombreP;
    sabor = saborP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Refresco::getNombre()
{
    return nombre;
}

string Refresco::getSabor()
{
    return sabor;
}

int Refresco::getPrecio()
{
    return precio;
}

int Refresco::getTamanio()
{
    return tamanio;
}

int Refresco::getCalorias()
{
    return calorias;
}

void Refresco::imprimirRefresco(){
    cout << "nombre: " << nombre << endl;
    cout << "Sabro: " << sabor << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//ALOCOHOOOOOOOOL #4
class Alcohol{
    private:
    string nombre;
    double porcentaje;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getNombre();
    double getPorcentaje();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirAlcohol();

    public:
    Alcohol();
    Alcohol(string nombreP, double porcentajeP, int precioP, int tamanioP, int caloriasP);
};

Alcohol::Alcohol(){}
Alcohol::Alcohol(string nombreP, double porcentajeP, int precioP, int tamanioP, int caloriasP)
{
    nombre = nombreP;
    porcentaje = porcentajeP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
};

string Alcohol::getNombre()
{
    return nombre;
}

double Alcohol::getPorcentaje()
{
    return porcentaje;
}

int Alcohol::getPrecio()
{
    return precio;
}

int Alcohol::getTamanio()
{
    return tamanio;
}

int Alcohol::getCalorias()
{
    return calorias;
}

void Alcohol::imprimirAlcohol(){
    cout << "Tipo: " << nombre << endl;
    cout << "Porcentaje de alcohol: " << porcentaje << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//ENERGETICAAAAAAA #5
class Energetica{
    private:
    string nombre;
    int cafeina;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getNombre();
    int getCafeina();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirEnergetica();

    public:
    Energetica();
    Energetica(string nombreP, int cafeinaP, int precioP, int tamanioP, int caloriasP);
};

Energetica::Energetica(){}
Energetica::Energetica(string nombreP, int cafeinaP, int precioP, int tamanioP, int caloriasP)
{
    nombre = nombreP;
    cafeina = cafeinaP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Energetica::getNombre()
{
    return nombre;
}

int Energetica::getCafeina()
{
    return cafeina;
}

int Energetica::getPrecio()
{
    return precio;
}

int Energetica::getTamanio()
{
    return tamanio;
}

int Energetica::getCalorias()
{
    return calorias;
}

void Energetica::imprimirEnergetica(){
    cout << "nombre: " << nombre << endl;
    cout << "Cantidad de cafeina: " << cafeina << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//GALLETAAAAAAS #6
class Galletas{
    private:
    string nombre;
    string sabor;
    int precio;
    int unidades;
    int calorias;

    public:
    string getNombre();
    string getSabor();
    int getPrecio();
    int getUnidades();
    int getCalorias(); 
    void imprimirGalletas();

    public:
    Galletas();
    Galletas(string nombreP, string saborP, int precioP, int unidadesP, int caloriasP);
};

Galletas::Galletas(){}
Galletas::Galletas(string nombreP, string saborP, int precioP, int unidadesP, int caloriasP)
{
    nombre = nombreP;
    sabor = saborP;
    precio = precioP;
    unidades = unidadesP;
    calorias = caloriasP;
};

string Galletas::getNombre()
{
    return nombre;
}

string Galletas::getSabor()
{
    return sabor;
}

int Galletas::getPrecio()
{
    return precio;
}

int Galletas::getUnidades()
{
    return unidades;
}

int Galletas::getCalorias()
{
    return calorias;
}

void Galletas::imprimirGalletas(){
    cout << "nombre: " << nombre << endl;
    cout << "Sabro: " << sabor << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Unidades: " << unidades << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//PAPAAAAAAAS #7
class Papas{
    private:
    string nombre;
    string picante;
    int precio;
    int peso;
    int calorias;

    public:
    string getNombre();
    string getPicante();
    int getPrecio();
    int getPeso();
    int getCalorias(); 
    void imprimirPapas();

    public:
    Papas();
    Papas(string nombreP, string picanteP, int precioP, int pesoP, int caloriasP);
};

Papas::Papas(){}
Papas::Papas(string nombreP, string picanteP, int precioP, int pesoP, int caloriasP)
{
    nombre = nombreP;
    picante = picanteP;
    precio = precioP;
    peso = pesoP;
    calorias = caloriasP;
}

string Papas::getNombre()
{
    return nombre;
}

string Papas::getPicante()
{
    return picante;
}

int Papas::getPrecio()
{
    return precio;
}

int Papas::getPeso()
{
    return peso;
}

int Papas::getCalorias()
{
    return calorias;
}

void Papas::imprimirPapas(){
    cout << "nombre: " << nombre << endl;
    cout << "Picante: " << picante<< " pican" << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Peso " << peso << "kg" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//HELADOOOOOOO #8
class Helados{
    private:
    string nombre;
    string tipo;
    string sabor;
    int precio;
    int calorias;

    public:
    string getNombre();
    string getTipo();
    string getSabor();
    int getPrecio();
    int getCalorias(); 
    void imprimirHelados();

    public:
    Helados();
    Helados(string nombreP, string tipoP, string saborP, int precioP, int caloriasP);
};

Helados::Helados(){}
Helados::Helados(string nombreP, string tipoP, string saborP, int precioP, int caloriasP)
{
    nombre = nombreP;
    tipo = tipoP;
    sabor = saborP;
    precio = precioP;
    calorias = caloriasP;
};

string Helados::getNombre()
{
    return nombre;
}

string Helados::getTipo()
{
    return tipo;
}

string Helados::getSabor()
{
    return sabor;
}

int Helados::getPrecio()
{
    return precio;
}

int Helados::getCalorias()
{
    return calorias;
}

void Helados::imprimirHelados(){
    cout << "nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Sabor: " << sabor << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//DULCEEEEEEES #9
class Dulces{
    private:
    string nombre;
    string tipo;
    int unidades;
    int precio;
    int calorias;

    public:
    string getNombre();
    string getTipo();
    int getUnidades();
    int getPrecio();
    int getCalorias(); 
    void imprimirDulces();

    public:
    Dulces();
    Dulces(string nombreP, string tipoP, int unidadesP, int precioP, int caloriasP);
};

Dulces::Dulces(){}
Dulces::Dulces(string nombreP, string tipoP, int unidadesP, int precioP, int caloriasP)
{
    nombre = nombreP;
    tipo = tipoP;
    unidades = unidadesP;
    precio = precioP;
    calorias = caloriasP;
};

string Dulces::getNombre()
{
    return nombre;
}

string Dulces::getTipo()
{
    return tipo;
}

int Dulces::getUnidades()
{
    return unidades;
}

int Dulces::getPrecio()
{
    return precio;
}

int Dulces::getCalorias()
{
    return calorias;
}

void Dulces::imprimirDulces(){
    cout << "nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Unidades: " << unidades << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//PIZZAAAAAAAAAAA #10
class Pizza{
    private:
    string nombre;
    string ingredientes;
    string tamanio;
    int precio;
    int calorias;

    public:
    string getNombre();
    string getIngredientes();
    string getTamanio();
    int getPrecio();
    int getCalorias(); 
    void imprimirPizza();

    public:
    Pizza();
    Pizza(string nombreP, string ingredientesP, string tamanioP, int precioP, int caloriasP);
};

Pizza::Pizza(){}
Pizza::Pizza(string nombreP, string ingredientesP, string tamanioP, int precioP, int caloriasP)
{
    nombre = nombreP;
    ingredientes = ingredientesP;
    tamanio = tamanioP;
    precio = precioP;
    calorias = caloriasP;
};

string Pizza::getNombre()
{
    return nombre;
}

string Pizza::getIngredientes()
{
    return ingredientes;
}

string Pizza::getTamanio()
{
    return tamanio;
}

int Pizza::getPrecio()
{
    return precio;
}

int Pizza::getCalorias()
{
    return calorias;
}

void Pizza::imprimirPizza(){
    cout << "nombre: " << nombre << endl;
    cout << "Ingredientes: " << ingredientes << endl;
    cout << "Tamaño: " << tamanio << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}
