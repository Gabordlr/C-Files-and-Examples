//By: Gabriel Rodriguez, A01027384
//Date: 2023/10/09
//Description: Program that finds the path of a maze using "backtracking" and "branch and bound"

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <set>
#include <cmath>
#include <string>

using namespace std;


vector<vector<int> > finalvector; //vector to store the path found using backtracking
vector<vector <int> > finalVectorBB; //vector to store the path found using branch and bound
vector<vector<int> > maze; //vector to store the maze
int rows; //number of rows of the maze
int cols; //number of columns of the maze


// Define possible moves (up, down, left, right)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// Define a structure to represent a node
struct Node {
    int x, y; // Current position
    int cost; // Cost to reach this node
    int h; // Heuristic cost (manhattan distance)
    vector<vector <int> > path; // Path to this node
};

// Custom comparison function for the priority queue
struct CompareCost {
    bool operator()(const Node& a, const Node& b) {
        //comapres cost by adding the cost and the heuristic cost (manhattan distance)
        return (a.cost + a.h) > (b.cost + b.h);
    }
};

// Function to calculate the manhattan distance from a cell to the exit
// to find how promising it is
int manhattanDistance(int x1, int y1) {
    return (x1 - rows - 2) + (y1 - cols - 2);
}

// function to find the path of a maze using branch and bound
// parameters: none (uses global variables)
// returns: vector<vector <int> > (vector containing the path)
// computational complexity: O(n*m) ~ O(n^2) however it always returns the best path
vector<vector <int> > branchAndBound() {
    priority_queue<Node, vector<Node>, CompareCost> pq; //priority queue to store the nodes
    set<vector <int> > visited; 

    Node startNode = {1, 1, 0, manhattanDistance(1, 1), {{1, 1}}}; //start the first node in 1,1
    pq.push(startNode); //push the first node to the priority queue

    while (!pq.empty()) { //while the priority queue is not empty loop
        Node currentNode = pq.top();
        pq.pop(); 

        int x = currentNode.x; //get the x index of the current node
        int y = currentNode.y; //get the y index of the current node
        int cost = currentNode.cost; //get the cost of the current node

        if (x == rows-2 && y == cols-2) { //if the current node is the exit, return the path
            return currentNode.path;
        }

        if (visited.count({x, y})) {
            continue;
        }

        visited.insert({x, y}); //insert the current node to the visited set to prevent loops

        // Explore neighbors
        for (int i = 0; i < 4; i++) { //loop to explore the neighbors of the current node in every direction
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (maze[newX][newY] != 0) { //if the neighbor is not a wall, push it to the priority queue
                Node neighborNode = {newX, newY, cost + 1, manhattanDistance(newX, newY), currentNode.path};
                neighborNode.path.push_back({newX, newY});
                pq.push(neighborNode);
            }
        }
    }

    // If no path is found, return an empty path
    return {};
}


//function to find the path of a maze using backtracking and recursion
//parameters: int y (y index), int x (x index), vector<vector<int> > &finalvector (vector to store the path)
//returns: bool (true if the path is found, false if not)
//computational complexity: O(n*m) ~ O(n^2) however is doesnt return the best path (it returns the first path found)
bool backTrackingHelper(int y, int x, vector<vector<int> > &finalvector){
    if (y == rows-2 && x == cols-2){ // base case, if the current node is the exit, return true
        finalvector.push_back({y, x}); //push the current node to the final vector
        return true;
    }
    else{
        maze[y][x] = 2; //mark the current node as visited to prevent loops
        for (int i = 0; i < 4; i++) { //loop to explore the neighbors of the current node in every direction
            int newX = x + dx[i];
            int newY = y + dy[i];

            //if the neighbor is not a wall, call the function again with the neighbor as the current node
            if (maze[newY][newX] == 1) { 
                //if the function returns true, push the current node to the final vector and return true
                if (backTrackingHelper(newY, newX, finalvector)) { 
                    finalvector.push_back({y, x});
                    return true;
                }
            }
        }

        //if the function returns false, keep exploring the other neighbors
        return false;
    }
}

//function to call the backtracking helper function initalizing the indexes in 1,1
//parameters: none (uses global variables)
//returns: vector<vector<int> > (vector containing the path)
//computational complexity: O(1)
vector<vector<int> > backtracking(){
    bool val = backTrackingHelper(1, 1, finalvector);
    if (val == false){
        return {};
    }
    return finalvector;
}


//function to read the maze from a file in the following format 
//rows cols
//maze values
void leeArchivo(string archivo)
{
    ifstream inputFile(archivo); // Open the file
    if (!inputFile) {
        cerr << "Error: File not found or cannot be opened." << endl;
    }

    int inRow, inCol;
    inputFile >> inRow >> inCol; // Read row and cols from the file

    rows = inRow + 2;
    cols = inCol + 2;

    vector<int> initMaze(inRow * inCol);

    for (int i = 0; i < inRow * inCol; i++) {
        inputFile >> initMaze[i]; // Read maze values from the file
    }


    //the maze is initialized with 0s in the borders and the values from the file in the middle
    //this 0s work as walls
    vector<vector<int> > tempVector(rows, vector<int>(cols));

    vector<int> realMaze(rows * cols, 0);

    for (int i = 0; i <= inRow; i++) {
        for (int j = 0; j <= inCol; j++) {
            realMaze[(i+1) * cols + (j+1)] = initMaze[i * inCol + j];
            tempVector[i][j] = realMaze[i * cols + j];
        }
    }
    
    maze = tempVector;

    inputFile.close(); // Close the file

}


void imprimeSolucion(){
    // If finalvector is empty, no path was found to the exit using backtracking
    if (finalvector.empty()) {
        cout << "No path found using Brute Force" << endl;
    }

    // If finalVectorBB is empty, no path was found to the exit using branch and bound
    if (finalVectorBB.empty()) {
        cout << "No path found using Branch and Bound" << endl;
    }

    vector<int> emptyVector(rows * cols, 0); // Initialize a new maze for printing
    vector<int> printedMaze(rows * cols, 0); // Initialize a new maze for printing

    // Mark the cells in the solved path
    for (int i = 0; i < finalvector.size(); ++i) {
        emptyVector[finalvector[i][0]*cols + finalvector[i][1]] = 1;
    }

    // Mark the cells in the solved path
    for (const auto& p : finalVectorBB) {
        printedMaze[p[0] * cols + p[1]] = 1;
    }

    //Shows the maze with the path found using backtracking
    cout << "Path found using Back Tracking: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j){
            cout << emptyVector[i*cols + j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl << endl;


    //Shows the maze with the path found using branch and bound
    cout << "Path found using Branch and Bound: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << printedMaze[i*cols + j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl << endl;
}


int main(){
    leeArchivo("laberinto.txt");
    
    // Print inicial vector
    cout << "Empty " << rows << "x" << cols << " maze: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------" << endl << endl;

    finalvector = backtracking();

    finalVectorBB = branchAndBound();

    imprimeSolucion();
}