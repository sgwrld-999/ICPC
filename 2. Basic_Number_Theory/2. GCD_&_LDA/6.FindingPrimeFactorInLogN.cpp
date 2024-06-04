#include <bits/stdc++.h>
#include <iostream> // Add missing include statement

using namespace std;

/*
Problem link : https://www.geeksforgeeks.org/prime-numbers/
Problem link on leetcode : https://leetcode.com/problems/count-primes/
Explanation : 
Approach 1: Brute force approach
            1. Run a loop from 2 to n 
                i. Check whether the number is divisible by any number from 2 to n - 1.
                ii. Store it in the vector 
                iii. Divide the number by the divisor and store the divisor in the vector.

            Time complexity: O(n)
Approach 2: Optimized approach
         Use of Sieve of Eratosthenes algorithm to find the prime numbers till n.
         but instead of storing the number we will store the prime factor of the number or the smallest prime factor of the number.   
        Time complexity: O(logn)
*/

int n = 1000000;
int primeFactors[1000001];
void sieveOEratosthenes() {

    primeFactors[0] = primeFactors[1] = 0;
    
    for(int i = 2 ; i <= n ; i++){
        primeFactors[i] = i;
    }

    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN ; i++) {
        if (primeFactors[i] == i) {
            for (int j = i; j <= n; j += i) {
                if (primeFactors[j] == j) {
                    primeFactors[j] = i;
                }
            }
        }
    }
}
class Solution {
    public:

    void primeFactorziationInLogN(int n){ // Add return type 'void' to the function
        while(n != 1){
            cout << primeFactors[n] << " ";
            n = n / primeFactors[n];
        }
    }
};

int main(){
    Solution obj;
    sieveOEratosthenes();
    int n = 450;
    obj.primeFactorziationInLogN(n);
    return 0;
}
