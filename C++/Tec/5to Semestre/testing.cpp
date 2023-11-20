#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    string archivo = "string.txt";
    int n = 24
    
    ifstream inputFile(archivo);
    
    vector<int> a(n, 0);
    
    char c;
    int col = 0;
    
    while (inputFile.get(c)) {
        a[col] += static_cast<int>(c);
        col++;
        
        if (col == n) {
            col = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] %= 256;
    }
    
    // Calcular el valor hexadecimal y almacenarlo en una cadena de salida
    stringstream hexString;
    for (int i = 0; i < n; i += 4) {
        int sum = a[i] + a[i + 1] + a[i + 2] + a[i + 3];
        int hexValue = sum % 256;
        hexString << setfill('0') << setw(2) << hex << hexValue;
    }
    
    cout << "Resultado: " << hexString.str() << endl;
    
    inputFile.close();
    return 0;
}