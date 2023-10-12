#include <iostream>
#include <map>

using namespace std;

map<int, int> init_map()
{
    map<int, int> fibmemo;
    fibmemo[0] = 0;
    fibmemo[1] = 1;
    return fibmemo;
}

map<int, int> fibmemo = init_map();

int fib(int n)
{
    if (fibmemo.find(n) != fibmemo.end())
    {
        return fibmemo[n];
    }
    else
    {
        int result = fib(n - 1) + fib(n - 2);
        fibmemo[n] = result;
        return result;
    }
}

int fibBruteForce(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    cout << "n: " << n << endl;
    return fibBruteForce(n - 1) + fibBruteForce(n - 2);
}

int main()
{
    int val = fib(30);
    cout << val << endl;
}
