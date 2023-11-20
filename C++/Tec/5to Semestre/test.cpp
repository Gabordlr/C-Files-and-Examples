#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


int main(){

    vector<int> a;
    vector<int> organizeA;

    a.push_back(1);
    a.push_back(6);
    a.push_back(5);
    a.push_back(2);
    a.push_back(4);
    
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if(a[i] < a[j]){
                organizeA.insert(organizeA.begin()+j, a[i])
            }
        }
    }

    for(int i = 0; i < organizeA.size(); i++){
        cout << organizeA[i] << endl;
    }

}