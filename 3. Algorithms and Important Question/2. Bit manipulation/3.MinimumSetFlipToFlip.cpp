#include<bits/stdc++.h>
using namespace std;
/*
Problem link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
Explanantion: 
We've to find the minimum number of flips to convert start to goal.
Let's understand with an example 
start = 10, goal = 7
10 = 1010
7 =  0111
We've to convert 1010 to 0111 so we've to flip 3 bits to convert 1010 to 0111.
So, the answer is 3.
Approach:
Since we've to find the minimum number of flips to convert start to goal it also says that we need to find the bits which are different in start and goal.
Since we are dealing with bits we can use XOR operator to find the bits which are different in start and goal.
As XOR is 1 when the bits are different and 0 when the bits are same.
If the bits are different then output will be 1 as XOR is odd ones detector.
xorOfStartAndGoal = start ^ goal == 10 ^ 7 == 1010 ^ 0111 == 1101 -> Number of 1's in 1101 is 3 so the answer is 3.
*/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal ;
        int count = 0 ;

        while(ans > 0){
            count++;
            ans = ans & (ans - 1);
        }

        return count;
    }
};

int main(){
    Solution s;
    cout << s.minBitFlips(2, 6) << endl;
    return 0;
}