#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Suduko Solver
Problem Link : https://leetcode.com/problems/sudoku-solver/
Explanation
The Suduko Solver is a classic problem of solving the suduko puzzle.
Let's say we've a empty box in the suduko puzzle and we've to fill it with the correct number.

To fill it correctly we've to consider the following conditions:
1. Check the row
2. Check the column
3. Check the 3x3 box

If all the conditions are satisfied then we can place the number at that position.

What we'll we do is we'll check for the empty box by iteratinf each row and col and if we find any empty box then we'll try to fill it with the correct number.
Rest explnanaition is in the code.
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //If the box is empty then we'll try to fill it with the correct number.
                if (board[i][j] == '.') {
                    //We'll check from 1 to 9 if the number can be placed at that position or not.
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            //If the number can be placed at that position then we'll check for the next box.
                            if (solve(board)) {
                                return true;
                            } else {//If the number can't be placed at that position then we'll backtrack.
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
            if (board[row][i] == ch) return false;
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == ch) return false;
        }
        return true;
    }
};
