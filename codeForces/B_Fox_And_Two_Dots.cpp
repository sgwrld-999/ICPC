#include<bits/stdc++.h>
using namespace std;

typedef pair<int, char> PositionAndCharacter;

bool visited[51][51]; // Tracks whether a cell has been visited
char grid[51][51]; // Represents the grid of characters
int directionX[] = {1, -1, 0, 0}; // Directions representing left, right, up, down
int directionY[] = {0, 0, 1, -1};
int rows, columns; // Dimensions of the grid
bool cycleFound = false; // Flag to indicate if a cycle has been found

// Depth-First Search function to explore the grid
void depthFirstSearch(int currentRow, int currentColumn, int previousRow, int previousColumn, char currentCharacter) {
    // Check for out-of-bounds or character mismatch
    if(currentRow < 1 || currentColumn < 1 || currentRow > rows || currentColumn > columns) return;
    if(grid[currentRow][currentColumn] != currentCharacter) return;

    // Check if the current cell has been visited before
    if(visited[currentRow][currentColumn]) {
        cycleFound = true;
        return;
    }

    // Mark the current cell as visited
    visited[currentRow][currentColumn] = true;

    // Explore the neighboring cells
    for(int direction = 0; direction < 4; direction++) {
        int nextRow = currentRow + directionX[direction];
        int nextColumn = currentColumn + directionY[direction];

        // Prevent the search from reversing direction
        if(nextRow == previousRow && nextColumn == previousColumn)
            continue;

        depthFirstSearch(nextRow, nextColumn, currentRow, currentColumn, currentCharacter);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visited, false, sizeof(visited)); // Initialize the visited array

    // Input the dimensions and characters of the grid
    cin >> rows >> columns;
    for(int row = 1; row <= rows; row++) {
        for(int column = 1; column <= columns; column++) {
            cin >> grid[row][column];
        }
    }

    // Check each cell in the grid
    for(int row = 1; row <= rows; row++) {
        for(int column = 1; column <= columns; column++) {
            if(!visited[row][column]) {
                depthFirstSearch(row, column, -1, -1, grid[row][column]);
                if(cycleFound) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl; // If no cycle is found after checking all cells
}
