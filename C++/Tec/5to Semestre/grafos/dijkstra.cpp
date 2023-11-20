//By: Gabriel Rodriguez, A01027384
//Date: 2023/09/11
//Description: Program that finds the minimum distance from one node to the 
//               rest of the nodes in a graph using Dijkstra's algorithm

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

vector<vector<pair<int, int> > >  graph;

struct Node {
    int selfNode;
    //pair<previous node, cost>
    pair<int, int> path;
};

//Function that reads the file and creates the adjacency list
void leeArchivos(string archivo)
{
    ifstream inputFile(archivo); // Open the file
    if (!inputFile) {
        cerr << "Error: File not found or cannot be opened." << endl;
    }


    //the first line of the file contains the number of nodes and the number of edges
    int numNodos, numAristas;
    inputFile >> numNodos >> numAristas;

    vector<vector<pair<int, int> > >  tempGraph(numNodos);

    int node1, node2, weight;

    //the rest of the file contains the edges in the following format (node1, node2, weight)
    for (int i = 0; i < numAristas; i++) {        
        inputFile >> node1 >> node2 >> weight;
        pair<int, int> edge;
        edge.first = node2;
        edge.second = weight;

        tempGraph[node1].push_back(edge);
    }

    //print the graph in from of an adjacency list
    for (int i=0; i<numNodos; i++){
        cout << i << ": ";
        for (int j=0; j<tempGraph[i].size(); j++){
            cout << "(" << tempGraph[i][j].first << ", " << tempGraph[i][j].second << ") ";
        }
        cout << endl;
    }

    graph = tempGraph;


    inputFile.close(); // Close the file
}

// Function that finds the minimum distance frpm one node to the rest of the nodes
// parameters: the node from which we want to find the minimum distance to the rest of the nodes
// return: a vector of nodes that contains the minimum distance from the node to the rest of the nodes
// complexity: O(m log n)
vector<Node> DijkstraAlgorythm(int node) {
    vector<Node> distances(graph.size(), { -1, {INT_MAX, -1} }); // Initialize distances
    vector<bool> visited(graph.size(), false); // Keep track of visited nodes

    // Set the distance from the source node to itself as 0
    distances[node].selfNode = node;
    distances[node].path = { 0, -1 };

    // Priority queue <cost, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, node));

    // While the priority queue is not empty
    while (!pq.empty()) {
        // Get the top element
        pair<int, int> top = pq.top();
        pq.pop();

        int cost = top.first;
        int node = top.second;

        // If the node has a path with a lower cost, ignore it
        if (cost > distances[node].path.first) {
            continue; 
        }

        // Explore neighbors
        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i].first;
            int newCost = cost + graph[node][i].second;
            if (newCost < distances[neighbor].path.first && !visited[neighbor]) {
                distances[neighbor].path.first = newCost;
                distances[neighbor].path.second = node;
                pq.push(make_pair(newCost, neighbor));
            }
        }

        // Mark node as visited
        visited[node] = true;
    }

    return distances;
}


//helper function to test the DijkstraAlgorythm function
void helper_DijkstraAlgroythm(){
    vector< Node> distances(graph.size());
    for(int i=0; i < graph.size(); i++){
        //calls the DijkstraAlgorythm function for every node in the graph
        distances = DijkstraAlgorythm(i);

        //prints the minimum distance from the node to the rest of the nodes
        for (int j = 0; j < distances.size(); j++) {
            cout << "Node " << i << " to Node "  << j << ": " << distances[j].path.first << endl;
        }
        cout << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
    }
}


int main()
{
    leeArchivos("./garph.txt");

    helper_DijkstraAlgroythm();
    return 0;
}
