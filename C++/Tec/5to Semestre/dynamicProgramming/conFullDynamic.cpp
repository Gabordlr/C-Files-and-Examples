#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

map<int, vector<int> > init_map()
{
    map<int, vector<int> > allCoins;

    return allCoins;
}

map<int, vector<int> > allCoins = init_map();

vector<int> minNumMonDPhelper(vector<int> datos, int n)
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
            temp = minNumMonDPhelper(datos, n - datos[i]);
            if (temp.size() == 0 || temp.size() < coins.size() - 1)
            {
                if (allCoins.find(n) != allCoins.end() && allCoins[n].size() < coins.size() - 1)
                {
                    return allCoins[n];
                }
                else
                {
                    temp.push_back(datos[i]);
                    coins = temp;
                    allCoins[n] = coins;
                }
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

vector<int> minNumMonDP(int n){
    vector<int> datos;
    datos.push_back(50);
    datos.push_back(30);
    datos.push_back(5);
    datos.push_back(1);

    return minNumMonDPhelper(datos, n);
}

int main()
{
    auto start = chrono::steady_clock::now();


    vector<int> coins = minNumMonDP(60);

    int size = coins.size();

    cout << "FINAL Monedas: ";
    for (int i = 0; i < size; i++)
    {
        cout << coins[i] << " ";
    }

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}