#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <chrono>

using namespace std;


vector<int> minNumMonDP(vector<int> datos, int n)
{
    vector<int> coins;
    vector<int> minCoins;

    vector<int> temp;

    if (n == 0)
    {
        return coins;
    }
    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i] < n)
        {
            temp = minNumMonDP(datos, n - datos[i]);
            if (temp.size() == 0 || temp.size() < coins.size() - 1)
            {
                temp.push_back(datos[i]);
                coins = temp;
            }
        }
        else if (datos[i] == n)
        {
            coins.push_back(datos[i]);
            return coins;
        }
    }

    return coins;
}

int main()
{
    auto start = chrono::steady_clock::now();
    vector<int> datos;
    datos.push_back(50);
    datos.push_back(30);
    datos.push_back(5);
    datos.push_back(1);

    vector<int> coins = minNumMonDP(datos, 60);

    int size = coins.size();

    cout << "FINAL Monedas: ";
    for (int i = 0; i < size; i++)
    {
        cout << coins[i] << " ";
    }
    cout << endl;

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}