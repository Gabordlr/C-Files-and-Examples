//By: Gabriel Rodriguez, A01027384
//Date: 2023/09/11
//Description: Program that finds the minimum distance from one node to the
//               rest of the nodes in a graph using Floyd Warshall algorithm

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

vector<vector<int> >  graph;

//Function that reads the file and creates the adjacency matrix
void leeArchivos(string archivo)
{
    ifstream inputFile(archivo); // Open the file
    if (!inputFile) {
        cerr << "Error: File not found or cannot be opened." << endl;
    }

    int numNodos, numAristas;
    inputFile >> numNodos >> numAristas;

    //create a matrix of size numNodos x numNodos filled with -1
    vector<vector<int> >  tempGraph(numNodos, vector<int>(numNodos, -1));

    int node1, node2, weight;
    for (int i = 0; i < numAristas; i++) {   
        if (i < numNodos){
            tempGraph[i][i] = 0;
        }
        inputFile >> node1 >> node2 >> weight;
        tempGraph[node1][node2] = weight;
    }

    for (int i=0; i<numNodos; i++){
        for (int j=0; j<numNodos; j++){
            cout << tempGraph[i][j] << " ";
        }
        cout << endl;
    }

    graph = tempGraph;
}

//Function that finds the minimum distance from one node to the rest of the nodes in a graph
//parameters: none (uses the global variable graph)
//returns: none (prints the results)
//complexity: O(n^3)
void FloydAlgorythm(){

    int numNodos = graph.size(); //number of nodes in the graph
    int currentVal, newVal; //variables to store the current and new values of the distance between nodes
        
    for(int k = 0; k < numNodos; k++){ //for each row
        for(int i = 0; i < numNodos; i++){ //for each column
            for(int j = 0; j < numNodos; j++){ //for each node
                if (graph[i][k] != -1 && graph[k][j] != -1){ //if the distance between the nodes is not -1 (infinite)
                    currentVal = graph[i][j];
                    newVal = graph[i][k] + graph[k][j];
                    if (currentVal <= -1){ //if the current value is -1 (infinite) then replace it with the new value
                        graph[i][j] = newVal;
                    }
                    else{ //if the current value is not -1 (infinite) then replace it with the minimum between the current value and the new value
                        graph[i][j] = min(currentVal, newVal);
                    }
                }
            }
        }
    }

    //print the results
    cout << endl;
    cout << "RESULTS" << endl;
    cout << "---------------" << endl;
    
    //print the graph in from of an adjacency matrix
    for (int i=0; i<numNodos; i++){
        for (int j=0; j<numNodos; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }t

    return ;
}

int main()
{
    leeArchivos("./garph.txt");
    FloydAlgorythm();
    return 0;   
}