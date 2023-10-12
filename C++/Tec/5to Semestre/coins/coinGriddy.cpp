#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> minNumMonGR(vector<int> datos, int n)
{
    vector<int> coins;
    int i = 0;
    while (n > 0)
    {
        if (datos[i] <= n)
        {
            coins.push_back(datos[i]);
            n -= datos[i];
            i = 0;
        }
        else
        {
            i++;
        }
    }

    return coins;
}

int main()
{
    vector<int> datos;
    datos.push_back(50);
    datos.push_back(30);
    datos.push_back(5);
    datos.push_back(1);

    vector<int> coins = minNumMonGR(datos, 60);

    int size = coins.size();

    cout << "Monedas: ";
    for (int i = 0; i < size; i++)
    {
        cout << coins[i] << " ";
    }
}