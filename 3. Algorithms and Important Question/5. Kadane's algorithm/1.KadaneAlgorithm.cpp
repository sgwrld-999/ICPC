//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Kadane's Algorithm
Problem link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
Explanation : https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/


*/

// } Driver Code Ends

#define ll long long 
class Solution {
  public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {

        // Your code here
        ll maxSum = INT_MIN ;
        ll curSum = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            
            curSum += arr[i];
            maxSum = max(maxSum,curSum);
            curSum = (curSum > 0) ? curSum : 0 ;
        }
        
        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends