#include <iostream>
#include <vector>

using namespace std;

// Define the dimensions of the maze
const int rows = 6;
const int cols = 6;

// Define possible moves (up, down, left, right)
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

// Function to check if a cell is valid
bool isValid(int x, int y, const vector<int>& maze) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x * cols + y] == 0;
}

// Recursive function to find the path
bool findPath(vector<int>& maze, int x, int y, int destX, int destY, vector<pair<int, int>>& path) {
    if (x == destX && y == destY) {
        // Reached the destination
        path.push_back({x, y});
        return true;
    }

    if (!isValid(x, y, maze)) {
        return false;
    }

    maze[x * cols + y] = 2;  // Mark the cell as visited

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (findPath(maze, nx, ny, destX, destY, path)) {
            path.push_back({x, y});
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> maze = {0, 0, 0, 0, 0, 0,
                        0, 1, 1, 1, 1, 0,
                        0, 1, 0, 1, 0, 0,
                        0, 1, 1, 0, 0, 0,
                        0, 0, 1, 1, 1, 0,
                        0, 0, 0, 0, 0, 0};

    int startX = 1, startY = 1;
    int endX = 4, endY = 4;

    vector<pair<int, int>> path;
    if (findPath(maze, startX, startY, endX, endY, path)) {
        cout << "Path found:\n";
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << "{" << it->first << "," << it->second << "} ";
        }
        cout << endl;
    } else {
        cout << "No path found.\n";
    }

    return 0;
}
