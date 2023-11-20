//By: Gabriel Rodriguez, A01027384
//Date: 2023/10/14
//Function that finds the hash string of a string

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

//function that was provided in class (is not being used)
long long prhf(string S){
    int n = S.length();
    int p = 31;
    int m = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;
    for (int i=0; i<n; i++){
        valorHash = (valorHash + (S[i] - 'a' + 1) * potencia) % m;
        potencia = (potencia * p) % m;
    }
    return valorHash;
}


//function that converts an int to a hex string
string intToHex(int value) {
    stringstream stream;
    stream << hex << value;
    return stream.str();
}

//function that reads a file and returns the content as a string
string readFileToString(string& filename) {
    string content;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            content += line + '\n';
        }
        file.close();
    } else {
        cerr << "Failed to open file: " << filename << endl; //print error message if the file could not be opened
    }

    return content;
}

//function that finds the hash string of a string
//parameters: string filename (name of the file to read), float n (number of groups to divide the string)
//returns: string (hash string)
//computational complexity: O(n)
string hashString(string filename, float n){

    string content = readFileToString(filename); //read the file and store the content in a string
    string hashString = ""; //string to store the hash string
    string hexString;

    int size = ceil(content.length()/n); //find the size of each group by dividing the length of the string by the number of groups and rounding up

    vector<int> hashArray(n, 0); //vector to store the hash sum of each group

    //the loops adds the index = 0 to group 0, index = 1 to group 1, index = 2 to group 2...
    //until it repeats such as index = 8 to group 0, index = 9 to group 1, index = 10 to group 2...
    for(int i = 0; i < n; i++){
        for(int j = 0; j < size; j++){ 
            if(j * n + i >= content.length()-1){ //if the index is out of bounds, add n to the hash sum
                // cout << "grupo " << i <<" [" << j << "]: " << n << "  index " << j * n + i <<  endl;
                hashArray[i] += n;
            }
            else{
                // cout << "grupo " << i <<" [" << j << "]: " << content[j * n + i] << "  index " << j * n + i <<  endl;
                hashArray[i] += static_cast<int>(content[j * n + i]); //add the ascii value of the character to the hash sum
            }
        }
    }

    //find the mod divided by 256
    for (int i = 0; i < n; i++) {
        // cout << "hashArray[" << i << "]: " << hashArray[i] << endl;
        hexString = intToHex(hashArray[i] % 256); //convert the mod to a hex string
        hashString += hexString; //concatenate the hex string to the hash string
    }

    return hashString; //return only the first n/4 characters of the hash string
}

int main(){
    vector<int> result;

    //insert the number of columns
    float column;

    cout << "Ingrese el numero de columnas: ";
    cin >> column;

    string hashResult;

    hashResult = hashString("string.txt", column);

    cout << "Final hash string: "  << hashResult << endl;
}

