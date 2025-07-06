#include<iostrem>
#include<vector>
/*
The solution of this problem is first finiding all the trees using the DFS, but that will be the solution of the O(Linear) which is causing the time limit exceed.
*/

class Solution {
public:
    // Depth First Search to generate numbers in lexicographical order
    void DFS(int curNum, vector<int>& res, vector<bool>& visited, int n){
        if(curNum > n) return;

        visited[curNum] = true;

        // We only add the number to the result vector after the initial call
        res.push_back(curNum);

        // Try to append 0-9 to the current number to go deeper in lex order
        for(int i = 0; i <= 9; i++){
            int temp = (curNum * 10) + i;
            if(temp > n) return;

            if (!visited[temp]) {
                DFS(temp, res, visited, n);
            }
        }
    }

    int findKthNumber(int n, int k) {
        vector<int> res;

        // We use visited[n+1] to ensure we don't access out-of-bound
        vector<bool> visited(n + 1, false);

        // Start DFS from 1 to 9, since numbers don't start with 0
        for(int i = 1; i <= 9; i++){
            if (i > n) break; // No need to go further
            DFS(i, res, visited, n);
        }

        // Return the k-th smallest in lexicographical order
        return res[k - 1];
    }
};


