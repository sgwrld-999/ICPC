#include<bits/stdc++.h>
using namespace std;
/*
Problem name: Sum of Two Integers
Problem Link: https://leetcode.com/problems/sum-of-two-integers/
Explanation : https://leetcode.com/problems/sum-of-two-integers/solutions/132479/simple-explanation-on-how-to-arrive-at-the-solution
*/

class Solution {
public:
    int getSum(int a, int b) {
        int carry ;
        while(b != 0){
            carry = (a & b);
            a = a ^ b;
            b = carry << 1 ;
        }

        return a;
    }
};