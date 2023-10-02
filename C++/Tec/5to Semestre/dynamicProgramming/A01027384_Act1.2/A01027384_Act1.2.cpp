//Gabriel Rodriguez De Los Reyes A01027384
//28/08/2023
//Actividad 1.2 Implementación de la técnica de programación "Programación dinámica" y "algoritmos avaros"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

//constructor del objeto map
map<int, vector<int> > init_map()
{
    map<int, vector<int> > allCoins;

    return allCoins;
}

//se inicializa el map
map<int, vector<int> > allCoins = init_map();

//se inicializa el vector global de las monedas
vector<int> globCoins;

//funcion recursiva para encontrar el minimo numero de monedas con programación dinamica
//Parametros: vector<int> datos (vector de monedas), int n (cambio)
//Retorno: vector<int> coins (vector de monedas con el minimo numero de monedas)
//Complejidad: O(n x m) en el peor caso donde n es el numero de monedas y m es el cambio
vector<int> minNumMonDPhelper(vector<int> datos, int n)
{
    //se inicializan los vectores temporales para guardar las monedas
    vector<int> coins;
    vector<int> temp;

    //caso base 
    if (n == 0)
    {
        return coins;
    }
    
    //se recorre el vector de monedas
    int size = datos.size();
    for (int i = 0; i < size; i++)
    {
        //si la moneda es menor que el cambio
        if (datos[i] < n)
        {
            //se llama a la funcion recursiva
            temp = minNumMonDPhelper(datos, n - datos[i]);

            //si el vector temporal es menor que el vector de monedas
            if (temp.size() == 0 || temp.size() < coins.size() - 1)
            {
                //se verifica si el vector temporal esta en el map y si es menor que el vector de monedas
                if (allCoins.find(n) != allCoins.end() && allCoins[n].size() < coins.size() - 1)
                {
                    return allCoins[n];
                }
                //si no se encuentra en el map, se calcula y posteriormente se agrega
                else
                {
                    temp.push_back(datos[i]);
                    coins = temp;
                    allCoins[n] = coins;
                }
            }
        }
        //si la moneda es igual al cambio se agrega al vector de monedas
        else if (datos[i] == n)
        {
            coins.push_back(datos[i]);
            return coins;
        }
    }

    return coins;
}

//funcion que llama a la funcion recursiva minNumMonDPhelper
vector<int> minNumMonDP(int n){

    vector<int> datos = globCoins;

    return minNumMonDPhelper(datos, n);
}

//funcion para encontrar el minimo numero de monedas con el metodo griddy
//Parametros: vector<int> datos (vector de monedas), int n (cambio)
//Retorno: vector<int> coins (vector de monedas con el minimo numero de monedas)
//Complejidad: O(n) en el peor caso donde n es el valor del cambio
vector<int> minNumMonGR(int n)
{
    //se inicializa el vector de monedas
    vector<int> datos = globCoins;  

    //se inicializa el vector del menor numero de monedas
    vector<int> coins;

    int i = 0;

    //se recorre el vector de monedas hasta que el cambio sea 0
    while (n > 0)
    {
        //si la moneda es menor o igual al cambio se agrega al vector de monedas
        if (datos[i] <= n)
        {
            //se agrega la moneda y se le resta el valor al cambio
            coins.push_back(datos[i]);
            n -= datos[i];
            i = 0;
        }
        else
        {
            //si la moneda es mayor al cambio se pasa a la siguiente moneda
            i++;
        }
    }

    return coins;
}

void escribeRespuesta(int n){
    //se inicializan los vectores para guardar los resultados
    vector<int> dynamicResult = minNumMonDP(n);
    vector<int> greedyResult = minNumMonGR(n);

    //se imprimen los resultados
    int size = dynamicResult.size();
    cout << "Monedas Dinamico: " << endl;
    for (int i = size; i > 0; i--)
    {
        cout << dynamicResult[i-1] << endl;
    }
    cout << endl;;

    size = greedyResult.size();
    cout << "Monedas Greedy: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << greedyResult[i] << endl;
    }
    cout << endl;

    return ;
}

int main()
{
    int n; int temp; int costo; int dinero;
    //se pide el numero de monedas
    cout << "Ingrese el numero de monedas: ";
    cin >> n;

    //se piden las monedas
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el valor de la moneda " << i + 1 << ": ";
        cin >> temp;
        globCoins.push_back(temp);
    }

    //se pide el costo y el dinero entregado
    cout << "Ingrese el costo total: ";
    cin >> costo;

    cout << "Ingrese el dinero entregado: ";
    cin >> dinero;

    //se calcula el cambio
    int resul = costo - dinero;

    //se llama a la funcion para escribir la respuesta
    escribeRespuesta(resul);
}