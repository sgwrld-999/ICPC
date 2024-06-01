#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Search in a 2D matrix
Problem link : https://leetcode.com/problems/search-a-2d-matrix/
Explanation :
Approach 1: Brute force
            Traverse the matrix and check if the target element is present.
            Time complexity: O(n*m)
            Space complexity: O(1)
Approach 2: Binary search
            Perform binary search on each row of the matrix.
            Time complexity: O(n*logm)
            Space complexity: O(1)
Approach 3: Binary search
            Treat the 2D matrix as a 1D array and perform binary search.
            Formula:
            row = mid / m -> Why it's working? -> The quotient of mid divided by m gives the row number as it is a 0-based index.
            col = mid % m -> Why it's working? -> The remainder of mid divided by m gives the column number as it is a 0-based index and first column is multiple of m.
            Time complexity: O(log(n*m))
            Space complexity: O(1)

*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(target == matrix[i][j]) return true;
            }
        }


        return false;
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0 ; i < row ; i++){
            int start = 0  ; 
            int end = col - 1 ;

            while(start <= end){
                int mid = start + (end - start) / 2 ;

                if(target == matrix[i][mid]){
                    return true;
                }
                else if(target > matrix[i][mid]){
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            } 
        }
        return false;
    }
};
class Solution3 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; // Check if the matrix is empty

        int low = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = (n * m) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 4}, {2, 5}};
    int target = 2;
    bool result = sol.searchMatrix(matrix, target);
    cout << (result ? "True" : "False") << endl;
    return 0;
}

