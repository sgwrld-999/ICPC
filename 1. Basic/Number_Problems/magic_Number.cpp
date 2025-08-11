//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem Link: https://practice.geeksforgeeks.org/problems/magic-number/0
Explanation : Find the product of all the elements of the array and then find the GCD of all the elements of the array.
Now find the power of the product of all the elements of the array raised to the power of GCD of all the elements of the array.
Return the result modulo 10^9+7.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Solution: https://chatgpt.com/share/6898c314-f660-8006-bd21-464573aee006

*/
// } Driver Code Ends

class Solution {
    static const int mod = 1e9 + 7; // Make it static const for better practice

public:
    int GCD(int a, int b) {
        if (b == 0) return a;
        else return GCD(b, a % b);
    }

    long long getVal(int N, int A[]) {
        if (N == 0) return 0; // Handle case where N is 0
        if (N == 1) return static_cast<long long>(std::pow(A[0], A[0])) % mod;

        long long product = 1; // Use long long to prevent overflow
        for (int i = 0; i < N; i++) { // Correct loop to include all elements
            product = (product * A[i]) % mod; // Apply modulo during multiplication
        }

        int gcd = A[0]; // Initialize gcd with the first element
        for (int i = 1; i < N; i++) { // Start from the second element
            gcd = GCD(A[i], gcd);
        }

        return static_cast<long long>(std::pow(product, gcd)) % mod; // Cast result of pow to long long
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.getVal(N,A) << endl;
    }
    return 0;
}
