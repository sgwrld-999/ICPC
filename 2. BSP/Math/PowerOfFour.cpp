#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        //to get x which is n=4^x 
        int x=log(pow(2,31))/log(4);
        int low = 0 , high = x;
        while(low <= high)
        {
            int mid=( low + high ) / 2;
            if(pow(4,mid)==n)
                return true;
            else if(pow(4,mid)<n)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (sol.isPowerOfFour(n)) {
        cout << n << " is a power of four." << endl;
    } else {
        cout << n << " is not a power of four." << endl;
    }
    return 0;
}
