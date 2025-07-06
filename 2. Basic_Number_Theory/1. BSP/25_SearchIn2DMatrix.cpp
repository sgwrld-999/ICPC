#include<bits/stdc++.h>
using namespace std;

/**
 * Thought Process:
 * ----------------
 * 1. **Problem Understanding**: 
 *    - Search target in 2D matrix where rows and columns are sorted
 *    - Each row's first element > previous row's last element (globally sorted)
 *    - Need efficient solution better than O(n*m) brute force
 * 
 * 2. **Key Insight**: 
 *    - Matrix can be treated as sorted 1D array when read row by row
 *    - Index mapping: 1D index → 2D coordinates
 *    - row = index / cols, col = index % cols
 *    - This allows binary search on entire matrix in O(log(n*m))
 * 
 * 3. **Multiple Approaches**:
 *    - **Brute Force**: Check every element - O(n*m) time
 *    - **Row-wise Binary Search**: Binary search each row - O(n*log m) time  
 *    - **Treat as 1D Array**: Single binary search - O(log(n*m)) time (optimal)
 * 
 * 4. **Optimal Approach (Treat as 1D)**:
 *    - Map 2D matrix to 1D conceptually: [0, 1, 2, ..., n*m-1]
 *    - For any 1D index 'mid': row = mid/m, col = mid%m
 *    - Perform standard binary search with this mapping
 *    - Effectively searching sorted array of size n*m
 * 
 * 5. **Why Index Mapping Works**:
 *    - Matrix is row-major order: [0][0], [0][1], ..., [0][m-1], [1][0], ...
 *    - Each row has m elements, so element at position i is at row i/m
 *    - Column position within row is i%m (remainder after dividing by row length)
 * 
 * 6. **Alternative: Row-wise Search**:
 *    - First find potential row (where target could exist)
 *    - Then binary search within that row
 *    - Less efficient but easier to understand
 * 
 * 7. **Edge Cases**:
 *    - Empty matrix: return false
 *    - Single element: direct comparison
 *    - Target smaller than matrix[0][0]: not found
 *    - Target larger than matrix[n-1][m-1]: not found
 * 
 * 8. **Complexity**:
 *    - Time: O(log(n*m)) for 1D approach, O(n*log m) for row-wise
 *    - Space: O(1) - constant extra space for all approaches
 */

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

