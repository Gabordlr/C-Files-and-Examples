#include <iostream>
#include <cmath>

using namespace std;

void suma(double a[], double b)
{
    a[1] = 20;
}

int main()
{
    double a[] = {3, 4, 5};
    double b = 2;
    double *c = a;
    suma(c, b);

    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << endl;
    }
}