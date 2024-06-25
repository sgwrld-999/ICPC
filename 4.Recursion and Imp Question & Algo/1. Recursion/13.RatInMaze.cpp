#include <vector>
#include <string>
using namespace std;
/*
Problem name : Rat in a Maze Problem
Problem Link : https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Solution:

Just check if there is a path from the starting cell to the ending cell and return all the paths.

*/
class Solution {
public:
    void solve(vector<vector<bool>>& visited, vector<string>& ans, vector<vector<int>>& a, string s, int row, int col, int n) {
        if (row == n-1 && col == n-1) {
            ans.push_back(s);
            return;
        }
        // Down
        if (row + 1 < n && !visited[row + 1][col] && a[row + 1][col] == 1) {
            visited[row + 1][col] = true;
            solve(visited, ans, a, s + 'D', row + 1, col, n);
            visited[row + 1][col] = false;
        }
        // Right
        if (col + 1 < n && !visited[row][col + 1] && a[row][col + 1] == 1) {
            visited[row][col + 1] = true;
            solve(visited, ans, a, s + 'R', row, col + 1, n);
            visited[row][col + 1] = false;
        }
        // Left
        if (col - 1 >= 0 && !visited[row][col - 1] && a[row][col - 1] == 1) {
            visited[row][col - 1] = true;
            solve(visited, ans, a, s + 'L', row, col - 1, n);
            visited[row][col - 1] = false;
        }
        // Up
        if (row - 1 >= 0 && !visited[row - 1][col] && a[row - 1][col] == 1) {
            visited[row - 1][col] = true;
            solve(visited, ans, a, s + 'U', row - 1, col, n);
            visited[row - 1][col] = false;
        }
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<string> ans;
        string path;
        if (m[0][0] == 1) { // Start solving only if the starting cell is 1
            visited[0][0] = true;
            solve(visited, ans, m, path, 0, 0, n);
        }
        return ans;
    }
};
