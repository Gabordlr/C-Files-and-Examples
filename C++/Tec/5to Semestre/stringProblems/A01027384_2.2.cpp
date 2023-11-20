//By: Gabriel Rodriguez, A01027384
//Date: 2023/10/14
//Function that finds the suffix array of a string

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Function that finds the suffix array of a string
//Parameters: string S (string to find the suffix array)
//returns: vector<int> (vector containing the suffix array)
//computational complexity: O(n^2)
vector<int> sufArr(string S) {
    vector<string> suffixArray;
    vector<int> values;
    S += "$"; //add $ to the end of the string
    int n = S.length(); //get the length of the string

    string phrase = ""; 

    //loop to find all the suffixes of the string
    for (int i = 1; i <= n; i++) {
        phrase = S[n-i] + phrase; //add the last character of the string to the beginning of the phrase
        suffixArray.push_back(phrase); //add the phrase to the suffix array
    }

    //sort the suffix array using the sort function
    sort(suffixArray.begin(), suffixArray.end());

    for (int i = 0; i < n; i++) {
        //adds the positions of the suffixes to the vector
        values.push_back(n + 1 - suffixArray[i].length());
    }


    return values;
}

int main() {
    string inputWord;

    cout << "Ingrese una palabra" << endl;
    getline(cin, inputWord); //get the input word
 
    //call the function to find the suffix array
    vector<int> result = sufArr(inputWord);

    //print the suffix array
    cout << "Final suffix array" << endl;

    for (int i = 0; i <= result.size()-1; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
