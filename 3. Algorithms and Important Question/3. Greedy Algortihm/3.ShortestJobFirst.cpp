//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
/*
Problem name: Shortest Job First
Problem link: https://practice.geeksforgeeks.org/problems/shortest-job-first5614/1
*/

// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size() ;
        sort(begin(bt),end(bt));
        
        int timeEx = 0 ;
        int waiting = 0 ;
        
        for(auto it : bt)
        {
            waiting += timeEx;
            timeEx += it ;
            
        }
        
        return waiting/n ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends