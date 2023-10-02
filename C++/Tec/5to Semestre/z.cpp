#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main(){
    string a;
    cout << "ingrese un string: ";
    cin >> a;

    vector<int> b;

    int n = 0;
    for (int i = 1; i < a.length(); i++)
    {
        for (int j = i; j < a.length(); j++)
        {
            if (a[j-i] == a[j])
            {
                n++;
                if (j == a.length() - 1)
                {
                    b.push_back(n);
                    n = 0;
                    break;
                }
            }
            else
            {
                b.push_back(n);
                n = 0;
                break;
            }
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << endl;
    }
}