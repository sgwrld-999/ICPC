#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement: Given two numbers a and b, we have to find the value of x and y such that
a*x + b*y = gcd(a, b)

Problem Link: https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
*/

class Solution {
public:
    int extendEuclideanAlgorithm(int a, int b, int& x, int& y) {
        // implementation of the function
        if(b == 0){
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int gcd = extendEuclideanAlgorithm(b, a%b, x1, y1);
        x = y1;
        y = x1 - (a/b)*y1;
        return gcd;
    }
};

int main() {
    Solution obj;
    int a = 35, b = 15;
    int x, y;
    cout << obj.extendEuclideanAlgorithm(a, b, x, y);
    return 0;
}
