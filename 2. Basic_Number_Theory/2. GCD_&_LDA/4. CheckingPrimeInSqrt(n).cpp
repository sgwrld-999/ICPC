#include<bits/stdc++.h>
using namespace std;
/*
Problem link : https://www.geeksforgeeks.org/prime-numbers/ 

Explanation: Given a number n, we have to check whether the number is prime or not. We can check whether a number is prime or not by checking whether the number is divisible by any number from 2 to sqrt(n). If the number is divisible by any number from 2 to sqrt(n), then the number is not prime. Otherwise, the number is prime.
Approach1: Checking from 2 to n - 1 and keeping a counter to check whether the number is divisible by more than 2 number or not. If the number is divisible by more than 2 numbers, then the number is not prime.
Approach2: Checking from 2 to sqrt(n) and keeping a counter to check whether the number is divisible by more than 2 number or not. If the number is divisible by more than 2 numbers, then the number is not prime.

Why Approach2 is better than Approach1?
Lets understand with and example :
Lets N = 36 
1 * 36 = 36
2 * 18 = 36
3 * 12 = 36
4 * 9 = 36 
6 * 6 = 36 from here the divisior will repeat so we can stop here and also sqrt(36) = 6 that means we can check till 6 only and we can get the answer for any number we can check till sqrt(n) only.
.
.
.

36
*/
class Solution {
    public: 
    bool primeOrNot(int n) {
        if (n == 1) {
            return false;
        }
        int ctr = 0;
        int sqrtN = sqrt(n);
        for (int i = 2; i < sqrtN; i++) {
            if (n % i == 0) {
                ctr++;
                if (ctr >= 2) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    int n = 13;
    cout << obj.primeOrNot(n);
    return 0;
}