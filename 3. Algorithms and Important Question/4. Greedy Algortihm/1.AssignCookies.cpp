//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Assign Cookies
Problem link: https://practice.geeksforgeeks.org/problems/assign-cookies-1587115620/1
Explanation: 

We've given two list one is greed and other is size of cookies. We have to find the maximum number of children that can be satisfied with the given cookies.

Brute approach:
1. Sort the greed and size of cookies.
2. Now, iterate over the greed and size of cookies.
3. If the greed of child is less than or equal to the size of cookie then increment the answer and move to the next child and cookie.
4. If the greed of child is greater than the size of cookie then move to the next cookie.
5. Return the answer.

Time complexity: O(nlogn) + O(mlogm) + O(n+m) = O(nlogn + mlogm)


*/

// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        int ans = 0 ;
        int n = greed.size();
        int m = sz.size();
        
        int gItr = 0 ;
        int sItr = 0 ;
        
        sort(begin(greed),end(greed));
        sort(begin(sz),end(sz));
        
        while(gItr < n && sItr < m)
        {
            if(greed[gItr] <= sz[sItr]){
                gItr++;
                ans++;
            }
            
            sItr++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends