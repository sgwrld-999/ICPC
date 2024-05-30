#include<bits/stdc++.h>
using namespace std;
/*
Problem name: Rows with max 1s
Problem link: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1
Explanation : 
Approach 1: Count the number of 1s in each row and keep track of the maximum count of 1s found so far. 
            Return the row index with the maximum count of 1s.
            Time complexity: O(n*m)
            Space complexity: O(1)

Approach 2: Use the upper_bound function to find the first 1 in each row.
            Calculate the number of 1s in the row by finding the distance between the first 1 and the end of the row.
            Update the answer if the current row has more 1s than the previous max.
            Time complexity: O(n*logm)
            Space complexity: O(1)
*/
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans = -1 ; 
	    int maxCtr = 0 ;
	    for(int i = 0 ; i < n ; i++){
	        int ctr = 0 ;
	        
	        for(int  j = 0 ; j < m ; j++){
	            if(arr[i][j] == 1){
	                ctr++;
	            }
	        }
	        
	        if(maxCtr < ctr){
	           maxCtr = ctr ;
	           ans = i ;
	        } 
	        ctr = 0 ;
	    }
	    
	    return ans ;
	}

};

class Solution1 {
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
        int ans = -1; // Initialize to -1 to indicate no rows with 1s found
        int maxCtr = 0; // To keep track of the maximum count of 1s

        for (int i = 0; i < n; i++) {
            // Find the first 1 in the row using upper_bound
            auto it = upper_bound(arr[i].begin(), arr[i].end(), 0);

            // Calculate the number of 1s in the row
            int ctr = distance(it, arr[i].end());

            // Update the answer if the current row has more 1s than the previous max
            if (maxCtr < ctr) {
                maxCtr = ctr;
                ans = i;
            }
        }

        return ans;
    }
};