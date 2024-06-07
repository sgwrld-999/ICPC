//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/*
Problem name: Find XOR in a range
Problem link: https://practice.geeksforgeeks.org/problems/find-xor-in-a-range4905/1
Explanation: 
It's a pattern either you know it or find the pattern
num = 1 : 1
num = 2 : 1^2 = 3
num = 3 : 1^2^3 = 0
num = 4 : 1^2^3^4 = 4


num = 5 : 1^2^3^4^5 = 1
num = 6 : 1^2^3^4^5^6 = 7
num = 7 : 1^2^3^4^5^6^7 = 0
num = 8 : 1^2^3^4^5^6^7^8 = 8


num = 9 : 1^2^3^4^5^6^7^8^9 = 1
num = 10 : 1^2^3^4^5^6^7^8^9^10 = 11
num = 11 : 1^2^3^4^5^6^7^8^9^10^11 = 0
num = 12 : 1^2^3^4^5^6^7^8^9^10^11^12 = 12


num = 13 : 1^2^3^4^5^6^7^8^9^10^11^12^13 = 1
num = 14 : 1^2^3^4^5^6^7^8^9^10^11^12^13^14 = 15
num = 15 : 1^2^3^4^5^6^7^8^9^10^11^12^13^14^15 = 0
num = 16 : 1^2^3^4^5^6^7^8^9^10^11^12^13^14^15^16 = 16


num = 17 : 1^2^3^4^5^6^7^8^9^10^11^12^13^14^15^16^17 = 1
num = 18 : 1^2^3^4^5^6^7^8^9^10^11^12^13^14^15^16^17^18 = 19
num = 19 : 1^2^3^4^5^6^7^8^9^10^11^12^13^14^15^16^17^18^19 = 0
num = 20 : 1^2^3^4^5^6^7^8^9^10^11^12^13^14^15^16^17^18^19^20 = 20

So, the pattern is:
num = 4n : num
num = 4n+1 : 1
num = 4n+2 : num+1
num = 4n+3 : 0

*/
// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int function(int num)
    {
        if(num%4 == 1) return 1;
        else if(num%4 ==2) return num + 1 ;
        else if(num%4 == 3) return 0 ;
        else return num;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return function(l-1) ^ function(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends