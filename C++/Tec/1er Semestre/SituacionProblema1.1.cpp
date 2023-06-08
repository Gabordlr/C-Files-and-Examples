#include<iostream>
#include<string>
#include "ClassesSP2.h"

using namespace std;

//===============================================Clase
class Cliente{
private:
    string nombreCompleto;
    int idCliente;
    int maxSizeLista;
    int contProductosComprados;
    string* listaNombresProductosComprados;
    double totalGastado;
    Cliente();

public:
    Cliente(string nombreCompletoP, int idClienteP);
    string getNombreCompleto();
    int getIdCliente();
    double getTotalGastado();
    void incrementarTotalGastado(int precio);
    void agregarProductoComprado(string nombreProducto);
};
Cliente::Cliente(){}
Cliente::Cliente(string nombreCompletoP, int idClienteP)
{
    nombreCompleto = nombreCompletoP;
    idCliente = idClienteP;
    maxSizeLista = 5;         
    contProductosComprados = 0;  
    listaNombresProductosComprados = new string[maxSizeLista];
}
void Cliente::agregarProductoComprado(string nombreProducto)
{
    listaNombresProductosComprados[contProductosComprados]=nombreProducto; 
    contProductosComprados++; 
}

void Cliente::incrementarTotalGastado(int precio)
{
    totalGastado += precio;
}

double Cliente::getTotalGastado()
{
    return totalGastado;
}

string Cliente::getNombreCompleto()
{
    return nombreCompleto;   
}

//===============================================Tienda
class Tienda{
private:
    int minStock;
    int maxClientes;
    int contadorClientes;
    int contadorCafeStock;
    int contadorJugoStock;
    int contadorRefrescoStock;
    int contadorAlcoholStock;
    int contadorEnergeticaStock;
    int contadorGalletasStock;
    int contadorPapasStock;
    int contadorHeladosStock;
    int contadorDulcesStock;
    int contadorPizzaStock;

    Cliente** listaClientes;
    Cafe** listaCafe;
    Jugo** listaJugo;
    Refresco** listaRefresco;
    Alcohol** listaAlcohol;
    Energetica** listaEnergetica;
    Galletas** listaGalletas;
    Papas** listaPapas;
    Helados** listaHelados;
    Dulces** listaDulces;
    Pizza** listaPizza;

    Tienda();

public:
    ~Tienda();
    
    Tienda(int minStockp);
    int getMinStock();
    void listarProducto();
    void imprimirVentas();

    void agregarCafe(Cafe* d);
    void agregarJugo(Jugo* d);
    void agregarRefresco(Refresco* d);
    void agregarAlcohol(Alcohol* d);
    void agregarEnergetica(Energetica* d);
    void agregarGalletas(Galletas* d);
    void agregarPapas(Papas* d);
    void agregarHelados(Helados* d);
    void agregarDulces(Dulces* d);
    void agregarPizza(Pizza* d);

    int getContadorCafeStock();
    int getContadorJugoStock();
    int getContadorRefrescoStock();
    int getContadorAlcoholStock();
    int getContadorEnergeticaStock();
    int getContadorGalletasStock();
    int getContadorPapasStock();
    int getContadorHeladosStock();
    int getContadorDulcesStock();
    int getContadorPizzaStock();

    void venderCafe(Cliente* usuario);
    void venderJugo(Cliente* usuario);
    void venderRefresco(Cliente* usuario);
    void venderAlcohol(Cliente* usuario);
    void venderEnergetica(Cliente* usuario);
    void venderGalletas(Cliente* usuario);
    void venderPapas(Cliente* usuario);
    void venderHelados(Cliente* usuario);
    void venderDulces(Cliente* usuario);
    void venderPizza(Cliente* usuario);


};

Tienda::~Tienda()
{
    delete[] listaCafe;
    delete[] listaJugo;
    delete[] listaRefresco;
    delete[] listaAlcohol;
    delete[] listaEnergetica;
    delete[] listaGalletas;
    delete[] listaPapas;
    delete[] listaHelados;
    delete[] listaDulces;
    delete[] listaPizza;

    delete[] listaClientes;
}

Tienda::Tienda(){}
Tienda::Tienda(int minStockp){
    minStock = minStockp;
    contadorCafeStock = 0;
    listaCafe = new Cafe*[minStock];

    contadorJugoStock = 0;
    listaJugo = new Jugo*[minStock];

    contadorRefrescoStock = 0;
    listaRefresco = new Refresco*[minStock];

    contadorAlcoholStock = 0;
    listaAlcohol = new Alcohol*[minStock];

    contadorEnergeticaStock = 0;
    listaEnergetica = new Energetica*[minStock];

    contadorGalletasStock = 0;
    listaGalletas = new Galletas*[minStock];

    contadorPapasStock = 0;
    listaPapas = new Papas*[minStock];

    contadorHeladosStock = 0;
    listaHelados = new Helados*[minStock];

    contadorDulcesStock = 0;
    listaDulces = new Dulces*[minStock];

    contadorPizzaStock = 0;
    listaPizza = new Pizza*[minStock];

    contadorClientes = 0;
    maxClientes = 10;
    listaClientes = new Cliente*[maxClientes];
}

int Tienda::getMinStock(){
    return minStock;
}

void Tienda::imprimirVentas()
{
    double totalVendido = 0;
    cout << "Clientes que compraron: " << endl;
    for (int i=0; i<contadorClientes; i++)
    {
        totalVendido += listaClientes[i]->getTotalGastado();
        cout << listaClientes[i]->getNombreCompleto() << " ";
    }
    cout << endl;
    cout << "El total vendido fue: " << totalVendido << endl;
}

void Tienda::listarProducto(){
    listaCafe[0]->imprimirCafe();
    cout << "Cafes en almacen: " << contadorCafeStock <<endl;
    listaJugo[0]->imprimirJugo();
    cout << "Jugos en almacen: " << contadorJugoStock <<endl;
    listaRefresco[0]->imprimirRefresco();
    cout << "refrescos en almacen: " << contadorRefrescoStock <<endl;
    listaAlcohol[0]->imprimirAlcohol();
    cout << "Alcoholes en almacen: " << contadorCafeStock <<endl;
    listaEnergetica[0]->imprimirEnergetica();
    cout << "Energeticas en almacen: " << contadorEnergeticaStock <<endl;
    listaGalletas[0]->imprimirGalletas();
    cout << "Galletas en almacen: " << contadorGalletasStock <<endl;
    listaPapas[0]->imprimirPapas();
    cout << "Papas en almacen: " << contadorPapasStock <<endl;
    listaHelados[0]->imprimirHelados();
    cout << "Helados en almacen: " << contadorHeladosStock <<endl;
    listaDulces[0]->imprimirDulces();
    cout << "Dulces en almacen: " << contadorDulcesStock <<endl;
    listaPizza[0]->imprimirPizza();
    cout << "Pizzas en almacen: " << contadorPizzaStock <<endl;
}

//CAFEEEE #1
void Tienda::agregarCafe(Cafe* d){
    listaCafe[contadorCafeStock] = d;
    contadorCafeStock++;
}

int Tienda::getContadorCafeStock(){
    return contadorCafeStock;
}

void Tienda::venderCafe(Cliente* usuario)
{
    cout << "Buenos dias, " << usuario->getNombreCompleto();
    cout << " pagarás " << listaCafe[0]->getPrecio() << " por el " << listaCafe[contadorCafeStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaCafe[contadorCafeStock-1]->getNombre());
    usuario->incrementarTotalGastado(listaCafe[0]->getPrecio());  
    contadorCafeStock--;    
    //listaCafe[contadorCafeStock-1] = 0; 
    listaClientes[contadorClientes] = usuario;
    contadorClientes++;
}

//JUGOOOO #2
void Tienda::agregarJugo(Jugo* d){
    listaJugo[contadorJugoStock] = d;
    contadorJugoStock++;
}

int Tienda::getContadorJugoStock(){
    return contadorJugoStock;
}

void Tienda::venderJugo(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaJugo[0]->getPrecio() << " por el " << listaJugo[contadorJugoStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaJugo[contadorJugoStock-1]->getNombre());  
    usuario->incrementarTotalGastado(listaJugo[0]->getPrecio());
    contadorJugoStock--;    
    //listaJugo[contadorJugoStock-1] = 0; 
    listaClientes[contadorClientes] = usuario; 
    contadorClientes++;
}

//REFRESCOOO #3
void Tienda::agregarRefresco(Refresco* d){
    listaRefresco[contadorRefrescoStock] = d;
    contadorRefrescoStock++;
}

int Tienda::getContadorRefrescoStock(){
    return contadorRefrescoStock;
}

void Tienda::venderRefresco(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaRefresco[0]->getPrecio() << " por el " << listaRefresco[contadorRefrescoStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaRefresco[contadorRefrescoStock-1]->getNombre()); 
    usuario->incrementarTotalGastado(listaRefresco[0]->getPrecio());
    contadorRefrescoStock--;
    //listaRefresco[contadorRefrescoStock-1] = 0;
    listaClientes[contadorClientes] = usuario; 
    contadorClientes++;
}

//ALCOHOOOOOL #4
void Tienda::agregarAlcohol(Alcohol* d){
    listaAlcohol[contadorAlcoholStock] = d;
    contadorAlcoholStock++;
}

int Tienda::getContadorAlcoholStock(){
    return contadorAlcoholStock;
}

void Tienda::venderAlcohol(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaAlcohol[0]->getPrecio() << " por el " << listaAlcohol[contadorAlcoholStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaAlcohol[contadorAlcoholStock-1]->getNombre());  
    usuario->incrementarTotalGastado(listaAlcohol[0]->getPrecio());
    contadorAlcoholStock--;   
    //listaAlcohol[contadorAlcoholStock-1] = 0;
    listaClientes[contadorClientes] = usuario; 
    contadorClientes++;
}

//ENERGETICAAAA #5
void Tienda::agregarEnergetica(Energetica* d){
    listaEnergetica[contadorEnergeticaStock] = d;
    contadorEnergeticaStock++;
}

int Tienda::getContadorEnergeticaStock(){
    return contadorEnergeticaStock;
}

void Tienda::venderEnergetica(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaEnergetica[0]->getPrecio() << " por el " << listaEnergetica[contadorEnergeticaStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaEnergetica[contadorEnergeticaStock-1]->getNombre()); 
    usuario->incrementarTotalGastado(listaEnergetica[0]->getPrecio());
    contadorEnergeticaStock--;    
    //listaEnergetica[contadorEnergeticaStock-1] = 0;
    listaClientes[contadorClientes] = usuario; 
    contadorClientes++;
}

//GALLETAAAAAS #6
void Tienda::agregarGalletas(Galletas* d){
    listaGalletas[contadorGalletasStock] = d;
    contadorGalletasStock++;
}

int Tienda::getContadorGalletasStock(){
    return contadorGalletasStock;
}

void Tienda::venderGalletas(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaGalletas[0]->getPrecio() << " por el " << listaGalletas[contadorGalletasStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaGalletas[contadorGalletasStock-1]->getNombre()); 
    usuario->incrementarTotalGastado(listaGalletas[0]->getPrecio());
    contadorGalletasStock--;   
    //listaGalletas[contadorGalletasStock-1] = 0; 
    listaClientes[contadorClientes] = usuario; 
    contadorClientes++;
}

//PAPAAAAAAS #7
void Tienda::agregarPapas(Papas* d){
    listaPapas[contadorPapasStock] = d;
    contadorPapasStock++;
}

int Tienda::getContadorPapasStock(){
    return contadorPapasStock;
}

void Tienda::venderPapas(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaPapas[0]->getPrecio() << " por el " << listaPapas[contadorPapasStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaPapas[contadorJugoStock-1]->getNombre()); 
    usuario->incrementarTotalGastado(listaPapas[0]->getPrecio());
    contadorPapasStock--; 
    //listaPapas[contadorPapasStock-1] = 0;
    listaClientes[contadorClientes] = usuario;
    contadorClientes++;
}

//HELADOOOOOO #8
void Tienda::agregarHelados(Helados* d){
    listaHelados[contadorHeladosStock] = d;
    contadorHeladosStock++;
}

int Tienda::getContadorHeladosStock(){
    return contadorHeladosStock;
}

void Tienda::venderHelados(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaHelados[0]->getPrecio() << " por el " << listaHelados[contadorHeladosStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaHelados[contadorHeladosStock-1]->getNombre());
    usuario->incrementarTotalGastado(listaHelados[0]->getPrecio());
    contadorHeladosStock--; 
    //listaHelados[contadorHeladosStock-1] = 0;
    listaClientes[contadorClientes] = usuario;
    contadorClientes++;
}

//DULCEEEEEEES #9
void Tienda::agregarDulces(Dulces* d){
    listaDulces[contadorDulcesStock] = d;
    contadorDulcesStock++;
}

int Tienda::getContadorDulcesStock(){
    return contadorDulcesStock;
}

void Tienda::venderDulces(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaDulces[0]->getPrecio() << " por el " << listaDulces[contadorDulcesStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaDulces[contadorDulcesStock-1]->getNombre()); 
    usuario->incrementarTotalGastado(listaDulces[0]->getPrecio());
    contadorDulcesStock--; 
    //listaDulces[contadorDulcesStock-1] = 0;
    listaClientes[contadorClientes] = usuario;
    contadorClientes++;
}

//PIZZAAAAAAA #10
void Tienda::agregarPizza(Pizza* d){
    listaPizza[contadorPizzaStock] = d;
    contadorPizzaStock++;
}

int Tienda::getContadorPizzaStock(){
    return contadorPizzaStock;
}

void Tienda::venderPizza(Cliente* usuario)
{
    cout << "Bienvenid@ " << usuario->getNombreCompleto();
    cout << " pagarás " << listaPizza[0]->getPrecio() << " por el " << listaPizza[contadorPizzaStock-1]->getNombre() << endl;
    usuario->agregarProductoComprado(listaPizza[contadorPizzaStock-1]->getNombre());
    usuario->incrementarTotalGastado(listaPizza[0]->getPrecio());
    contadorPizzaStock--;
    //listaPizza[contadorPizzaStock-1] = 0;
    listaClientes[contadorClientes] = usuario;
    contadorClientes++;
}

int main(){

    Cafe nescafe("Nescafe", "Americano", 12, 100, 1); //1
    Jugo delValle("DelValle Company", "Manzana", 35, 355, 250); //2
    Refresco cocaCola("Coca Cola", "Cola", 20, 355, 310); //3
    Alcohol tequila("Don Julio", 36.5, 1100, 750, 200); //4
    Energetica redBull("RedBull", 300, 150, 250, 275); //5
    Galletas oreo_negras("Oreo", "Chocolate", 80, 4, 175); //6
    Papas sabritas_fuego("Sabritas", "si", 17, 200, 325); //7
    Helados golazo("Golazo Efe", "Cono", "Vainilla", 130, 250); //8
    Dulces gomitas("PandaMix", "Panditas", 25, 50, 100); //9
    Pizza pepperoni("Papa Jhon", "Pepperoni", "Grande", 250, 270); //10
    Pizza champiniones("Costco", "Pepperoni", "Grande", 200, 270);


    Tienda quiosco(5);
    quiosco.agregarCafe(&nescafe);
    quiosco.agregarJugo(&delValle);
    quiosco.agregarRefresco(&cocaCola);
    quiosco.agregarAlcohol(&tequila);
    quiosco.agregarEnergetica(&redBull);
    quiosco.agregarGalletas(&oreo_negras);
    quiosco.agregarPapas(&sabritas_fuego);
    quiosco.agregarHelados(&golazo);
    quiosco.agregarDulces(&gomitas);
    quiosco.agregarPizza(&pepperoni);
    quiosco.agregarPizza(&champiniones);

    quiosco.listarProducto();

    Cliente usuario1("Juan", 111);
    Cliente usuario2("Luis", 222);
    Cliente usuario3("Jorge", 333);

    quiosco.venderCafe(&usuario1);
    quiosco.venderPizza(&usuario2);
    quiosco.venderPizza(&usuario2);
    quiosco.venderDulces(&usuario3);


    quiosco.imprimirVentas();


    //quiosco.listarProducto();
}
