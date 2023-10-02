#include <iostream>

using namespace std;

int fib(int i)
{
    if (i <= 1)
    {
        return i;
    }
    else
    {
        return fib(i - 1) + fib(i - 2);
    }
}

int fibSuma(int n)
{
    int F[n + 1];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

int main()
{
    int n;
    cout << "n: ";
    cin >> n;
    cout << fibSuma(n) << endl;
    // cout << fib(n) << endl;
}