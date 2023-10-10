#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


vector<vector<int> > twoDvector;
vector<vector<int> > finalvector;
int row;
int col;


bool backTrackingHelper(int y, int x, vector<vector<int> > &finalvector){
    if (y == row-2 && x == col-2){
        finalvector.push_back({y, x});
        return true;
    }
    else{
        twoDvector[y][x] = 2;
        if(twoDvector[y][x-1] == 1){
            if (backTrackingHelper(y, x-1, finalvector)){
                finalvector.push_back({y, x});
                return true;
            }
        }
        if(twoDvector[y+1][x] == 1){
            if (backTrackingHelper(y+1, x, finalvector)){
                finalvector.push_back({y, x});
                return true;
            }
        }
        if(twoDvector[y][x+1] == 1){
            if (backTrackingHelper(y, x+1, finalvector)){
                finalvector.push_back({y, x});
                return true;
            }
        }
        if(twoDvector[y-1][x] == 1){
            if (backTrackingHelper(y-1, x, finalvector)){
                finalvector.push_back({y, x});
                return true;
            }
        }
        return false;
    }
}

vector<vector<int> > backTracking(){
    vector<vector<int> > finalvector;
    int y = 1;
    int x = 1;
    int val = backTrackingHelper(y, x, finalvector);
    return finalvector;
}

void leeArchivos(string archivo)
{
    ifstream inputFile(archivo); // Open the file
    if (!inputFile) {
        cerr << "Error: File not found or cannot be opened." << endl;
    }

    int inRow, inCol;
    inputFile >> inRow >> inCol; // Read row and col from the file

    row = inRow + 2;
    col = inCol + 2;

    vector<int> maze(inRow * inCol);

    for (int i = 0; i < inRow * inCol; i++) {
        inputFile >> maze[i]; // Read maze values from the file
    }

    vector<vector<int> > tempVector(row, vector<int>(col));

    vector<int> realMaze(row * col, 0);

       // Copy the original maze into the center of the new maze
    for (int i = 0; i <= inRow; i++) {
        for (int j = 0; j <= inCol; j++) {
            realMaze[(i+1) * col + (j+1)] = maze[i * inCol + j];
            tempVector[i][j] = realMaze[i * col + j];
        }
    }
    
    twoDvector = tempVector;


    inputFile.close(); // Close the file

}

void imprimeSolucion(){
    vector<int> emptyVector(row * col, 0);

    for (int i = 0; i < finalvector.size(); ++i) {
        emptyVector[finalvector[i][0]*col + finalvector[i][1]] = 1;
    }

    // Print the 4y4 vector
    cout << "Final vector: " << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j){
            cout << emptyVector[i*col + j] << " ";
        }
        cout << endl;
    }

}


int main(){
    leeArchivos("laberinto.txt");
    
    // Print the 6x6 vector
    cout << "Empty " << row << "x" << col << " vector: " << endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j){
            cout << twoDvector[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------" << endl;

    finalvector = backTracking();

    imprimeSolucion();

}