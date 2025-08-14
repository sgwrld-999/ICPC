//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/*

Problem name : Maximum Product Subarray
Problem link : https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
Explanation : https://www.geeksforgeeks.org/maximum-product-subarray/


 */
// } Driver Code Ends
//User function template for C++
#define ll long long
class Solution {
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n) {
        if (n == 0) return 0;

        ll maxEnd = arr[0];
        ll minEnd = arr[0];
        ll maxPdt = arr[0];
        
        for (int i = 1; i < n; i++) {
            ll tempMax = maxEnd; 
            maxEnd = max({(ll)arr[i], arr[i] * maxEnd, arr[i] * minEnd});
            minEnd = min({(ll)arr[i], arr[i] * tempMax, arr[i] * minEnd});
            
            maxPdt = max(maxPdt, maxEnd);
        }
        
        return maxPdt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends