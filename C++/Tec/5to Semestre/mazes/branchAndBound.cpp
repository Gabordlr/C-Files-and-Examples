#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <set>

using namespace std;

// Define the maze as a 2D array (0 for open, 1 for wall)
int rows;
int cols;
vector<vector<int> > maze;


// Define possible moves (up, down, left, right)
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// Define a structure to represent a node
struct Node {
    int x, y; // Current position
    int cost; // Cost to reach this node
    vector<vector <int> > path; // Path to this node
};

// Custom comparison function for the priority queue
struct CompareCost {
    bool operator()(const Node& a, const Node& b) {
        return a.cost > b.cost; // Min-heap based on cost
    }
};

// Function to check if a cell is valid (within bounds and not a wall)
bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != 0;
}

// Branch and Bound Maze Solver
vector<vector <int> > branchAndBound() {
    priority_queue<Node, vector<Node>, CompareCost> pq;
    set<vector <int> > visited;

    Node startNode = {1, 1, 0, {{1, 1}}};
    pq.push(startNode);

    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();

        int x = currentNode.x;
        int y = currentNode.y;
        int cost = currentNode.cost;

        if (x == rows-2 && y ==  cols-2) {
            return currentNode.path;
        }

        if (visited.count({x, y})) {
            continue;
        }

        visited.insert({x, y});

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY)) {
                Node neighborNode = {newX, newY, cost + 1, currentNode.path};
                neighborNode.path.push_back({newX, newY});
                pq.push(neighborNode);
            }
        }
    }

    // If no path is found, return an empty path
    return {};
}

void leeArchivos(string archivo)
{
    ifstream inputFile(archivo); // Open the file
    if (!inputFile) {
        cerr << "Error: File not found or cannot be opened." << endl;
    }

    int inRow, inCol;
    inputFile >> inRow >> inCol; // Read row and col from the file

    rows = inRow + 2;
    cols = inCol + 2;

    vector<int> preMaze(inRow * inCol);

    for (int i = 0; i < inRow * inCol; i++) {
        inputFile >> preMaze[i]; // Read maze values from the file
    }

    vector<vector<int> > tempVector(rows, vector<int>(cols));

    vector<int> realMaze(rows * cols, 0);

       // Copy the original maze into the center of the new maze
    for (int i = 0; i <= inRow; i++) {
        for (int j = 0; j <= inCol; j++) {
            realMaze[(i+1) * cols + (j+1)] = preMaze[i * inCol + j];
            tempVector[i][j] = realMaze[i * cols + j];
        }
    }
    
    maze = tempVector;


    inputFile.close(); // Close the file
}

int main() {
    leeArchivos("laberinto.txt");

    cout << "Final vector: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector <int> > path = branchAndBound();

    if (path.empty()) {
    cout << "No path found!" << endl;
} else {
    cout << "Path found:" << endl;
    vector<int> printedMaze(rows * cols, 0); // Initialize a new maze for printing

    // Mark the cells in the solved path
    for (const auto& p : path) {
        printedMaze[p[0] * cols + p[1]] = 1;
    }

    // Print the marked maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << printedMaze[i*cols + j] << " ";
        }
        cout << endl;
    }
}

    return 0;
}
