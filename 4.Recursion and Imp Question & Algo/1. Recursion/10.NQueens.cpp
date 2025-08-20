#include<bits/stdc++.h>
using namespace std;
#include<string>
/*
Problem name : N-Queens Problem
Problem Link : https://leetcode.com/problems/n-queens/
Explanation  : 

The N-Queens problem is a classic problem of placing N queens on an N×N chessboard so that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space, respectively.

we've to check all the possiblities so we've to do it by recursion and bactracking.
Three condition to check if the queen can be placed at that position or not.
1. Check the column
2. Check the left diagonal
3. Check the right diagonal

If all the conditions are satisfied then we can place the queen at that position.

What we'll do is we put it in the first row and then we'll check for the next row and so on.

Rest is in the code.

time c
*/
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        int dupRow = row ;
        int dupCol = col ;
        // Check upper diagonal
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        row = dupRow ;
        col = dupCol ;

        while(dupCol >= 0){
            if(board[dupRow][dupCol] == 'Q'){
                return false;
            }
            dupCol--;
        }

        dupRow = row ;
        dupCol = col ;


        while(dupCol >= 0 && dupRow < n){
            if(board[dupRow][dupCol] == 'Q'){
                return false;
            }
            dupRow++;
            dupCol--;
        }


        return true;
    }
    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(row,col, board,n)){
                board[row][col] = 'Q';
                solve(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n,'.');
        for(int i = 0 ; i < n ; i++){
            board[i] = s ;
        }

        solve(0,ans, board, n);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(10);
    for(auto x : ans){
        for(auto y : x){
            cout << y << endl;
        }
        cout << endl;
    }
    return 0;
}