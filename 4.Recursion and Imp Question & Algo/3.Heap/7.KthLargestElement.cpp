//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    vector<int> kthLargest(int k, int arr[], int n) {
       priority_queue<int,vector<int>,greater<int>> pq;
       vector<int> ans(n,-1);
       int ctr = 0 ;
       for(int i = 0 ; i < n ; i++){
           pq.push(arr[i]);
           if(pq.size()>k)pq.pop();
           if(pq.size() == k) ans[i] = pq.top();
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends