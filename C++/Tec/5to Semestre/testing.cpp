#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void suma(double a[], double b)
{
    a[1] = 20;
}

vector<int> testList(vector<int> a, int count)
{
    cout << "count: " << count << endl;
    vector<int> b;
    if (count > 0){
        a.push_back(count);
        b = testList(a, count - 1);

        //testing zone
        cout << "testing zone" << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << endl;
        }

        return b;
    }
}

int main()
{
    vector<int> a;
    
    vector<int> b = testList(a, 5);

    cout << "testing zone out" << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << endl;
    }

}
