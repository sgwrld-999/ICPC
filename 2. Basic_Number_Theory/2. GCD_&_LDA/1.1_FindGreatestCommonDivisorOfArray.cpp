#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

/*
Problem Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
Approach:
    1. Find the maximum and minimum elements in the array.
    2. Use the GCD function to find the GCD of the maximum and minimum elements.
*/
class Solution {
public:

    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int max_Element = *max_element(nums.begin(),nums.end());
        int min_Element = *min_element(nums.begin(),nums.end());

        return gcd(max_Element,min_Element);
    }
};

/*
Python code:
def solution():
    def gcd(a,b):
        if b == 0:
            return 0

    def findGCD(nums):
        max_Element = max(nums)
        min_Element = min(nums)

        return gcd(max_Element,min_Element)
*/