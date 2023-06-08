#include<iostream>
#include<string>

using namespace std;


//CAFEEEE #1
class Cafe{
    private:
    string productor;
    string tipo;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getProductor();
    string getTipo();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirCafe();

    public:
    Cafe();
    Cafe(string productorP, string tipoP, int precioP, int tamanioP, int caloriasP);
};

Cafe::Cafe(string productorP, string tipoP, int precioP, int tamanioP, int caloriasP)
{
    productor = productorP;
    tipo = tipoP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Cafe::getProductor()
{
    return productor;
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
    cout << "Productor: " << productor << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//JUGOOOO #2
class Jugo{
    private:
    string productor;
    string fruta;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getProductor();
    string getFruta();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirJugo();

    public:
    Jugo(

    );
    Jugo(string productorP, string frutaP, int precioP, int tamanioP, int caloriasP);
};

Jugo::Jugo(string productorP, string frutaP, int precioP, int tamanioP, int caloriasP)
{
    productor = productorP;
    fruta = frutaP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Jugo::getProductor()
{
    return productor;
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
    cout << "Productor: " << productor << endl;
    cout << "Fruta: " << fruta << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//REFRESCOOOOO #3
class Refresco{
    private:
    string marca;
    string sabor;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getMarca();
    string getSabor();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirRefresco();

    public:
    Refresco();
    Refresco(string marcaP, string saborP, int precioP, int tamanioP, int caloriasP);
};

Refresco::Refresco(string marcaP, string saborP, int precioP, int tamanioP, int caloriasP)
{
    marca = marcaP;
    sabor = saborP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Refresco::getMarca()
{
    return marca;
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
    cout << "Marca: " << marca << endl;
    cout << "Sabro: " << sabor << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//ALOCOHOOOOOOOOL #4
class Alcohol{
    private:
    string tipo;
    double porcentaje;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getTipo();
    double getPorcentaje();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirAlcohol();

    public:
    Alcohol();
    Alcohol(string tipoP, double porcentajeP, int precioP, int tamanioP, int caloriasP);
};

Alcohol::Alcohol(string tipoP, double porcentajeP, int precioP, int tamanioP, int caloriasP)
{
    tipo = tipoP;
    porcentaje = porcentajeP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
};

string Alcohol::getTipo()
{
    return tipo;
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
    cout << "Tipo: " << tipo << endl;
    cout << "Porcentaje de alcohol: " << porcentaje << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//ENERGETICAAAAAAA #5
class Energetica{
    private:
    string marca;
    int cafeina;
    int precio;
    int tamanio;
    int calorias;

    public:
    string getMarca();
    int getCafeina();
    int getPrecio();
    int getTamanio();
    int getCalorias(); 
    void imprimirEnergetica();

    public:
    Energetica();
    Energetica(string marcaP, int cafeinaP, int precioP, int tamanioP, int caloriasP);
};

Energetica::Energetica(string marcaP, int cafeinaP, int precioP, int tamanioP, int caloriasP)
{
    marca = marcaP;
    cafeina = cafeinaP;
    precio = precioP;
    tamanio = tamanioP;
    calorias = caloriasP;
}

string Energetica::getMarca()
{
    return marca;
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
    cout << "Marca: " << marca << endl;
    cout << "Cantidad de cafeina: " << cafeina << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Tamaño: " << tamanio << "ml" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//GALLETAAAAAAS #6
class Galletas{
    private:
    string marca;
    string sabor;
    int precio;
    int unidades;
    int calorias;

    public:
    string getMarca();
    string getSabor();
    int getPrecio();
    int getUnidades();
    int getCalorias(); 
    void imprimirGalletas();

    public:
    Galletas();
    Galletas(string marcaP, string saborP, int precioP, int unidadesP, int caloriasP);
};

Galletas::Galletas(string marcaP, string saborP, int precioP, int unidadesP, int caloriasP)
{
    marca = marcaP;
    sabor = saborP;
    precio = precioP;
    unidades = unidadesP;
    calorias = caloriasP;
};

string Galletas::getMarca()
{
    return marca;
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
    cout << "Marca: " << marca << endl;
    cout << "Sabro: " << sabor << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Unidades: " << unidades << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//PAPAAAAAAAS #7
class Papas{
    private:
    string marca;
    string picante;
    int precio;
    int peso;
    int calorias;

    public:
    string getMarca();
    string getPicante();
    int getPrecio();
    int getPeso();
    int getCalorias(); 
    void imprimirPapas();

    public:
    Papas();
    Papas(string marcaP, string picanteP, int precioP, int pesoP, int caloriasP);
};

Papas::Papas(string marcaP, string picanteP, int precioP, int pesoP, int caloriasP)
{
    marca = marcaP;
    picante = picanteP;
    precio = precioP;
    peso = pesoP;
    calorias = caloriasP;
}

string Papas::getMarca()
{
    return marca;
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
    cout << "Marca: " << marca << endl;
    cout << "Picante: " << picante<< " pican" << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Peso " << peso << "kg" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//HELADOOOOOOO #8
class Helados{
    private:
    string marca;
    string tipo;
    string sabor;
    int precio;
    int calorias;

    public:
    string getMarca();
    string getTipo();
    string getSabor();
    int getPrecio();
    int getCalorias(); 
    void imprimirHelados();

    public:
    Helados();
    Helados(string marcaP, string tipoP, string saborP, int precioP, int caloriasP);
};

Helados::Helados(string marcaP, string tipoP, string saborP, int precioP, int caloriasP)
{
    marca = marcaP;
    tipo = tipoP;
    sabor = saborP;
    precio = precioP;
    calorias = caloriasP;
};

string Helados::getMarca()
{
    return marca;
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
    cout << "Marca: " << marca << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Sabor: " << sabor << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}


//DULCEEEEEEES #9
class Dulces{
    private:
    string marca;
    string tipo;
    int unidades;
    int precio;
    int calorias;

    public:
    string getMarca();
    string getTipo();
    int getUnidades();
    int getPrecio();
    int getCalorias(); 
    void imprimirDulces();

    public:
    Dulces();
    Dulces(string marcaP, string tipoP, int unidadesP, int precioP, int caloriasP);
};

Dulces::Dulces(string marcaP, string tipoP, int unidadesP, int precioP, int caloriasP)
{
    marca = marcaP;
    tipo = tipoP;
    unidades = unidadesP;
    precio = precioP;
    calorias = caloriasP;
};

string Dulces::getMarca()
{
    return marca;
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
    cout << "Marca: " << marca << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Unidades: " << unidades << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}

//PIZZAAAAAAAAAAA #10
class Pizza{
    private:
    string marca;
    string ingredientes;
    string tamanio;
    int precio;
    int calorias;

    public:
    string getMarca();
    string getIngredientes();
    string getTamanio();
    int getPrecio();
    int getCalorias(); 
    void imprimirPizza();

    public:
    Pizza();
    Pizza(string marcaP, string ingredientesP, string tamanioP, int precioP, int caloriasP);
};

Pizza::Pizza(string marcaP, string ingredientesP, string tamanioP, int precioP, int caloriasP)
{
    marca = marcaP;
    ingredientes = ingredientesP;
    tamanio = tamanioP;
    precio = precioP;
    calorias = caloriasP;
};

string Pizza::getMarca()
{
    return marca;
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
    cout << "Marca: " << marca << endl;
    cout << "Ingredientes: " << ingredientes << endl;
    cout << "Tamaño: " << tamanio << endl;
    cout << "Precio: " << precio << "$" << endl;
    cout << "Calorias: " << calorias << "kcal" << endl;
    cout << "============" << endl;
}
