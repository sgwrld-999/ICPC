#include <bits/stdc++.h>
using namespace std;
/*
Problem link on leetcode :  https://leetcode.com/problems/count-primes/
Problem link on geeksforgeeks : https://www.geeksforgeeks.org/sieve-of-eratosthenes/
Explanation:
Approach1: Brute force approach 
           Run a loop from 2 to n and check whether the number is prime or not. If the number is prime, then add the number to the primeNumbers vector.
            Time complexity: O(n * sqrt(n))
Approach2: Sieve of Eratosthenes
            We will create a boolean array of size n + 1 and initialize all the values to true. We will mark 0 and 1 as false as they are not prime numbers. We will run a loop from 2 to sqrt(n) and if the number is prime, then we will mark all the multiples of the number as false. We will return all the numbers which are prime.
            Time complexity: O(n * log(log(n)))
            Space complexity: O(n)
*/
/*
### Sieve of Eratosthenes 
    - Theory: 
    - Explanation: 
        - Considering we've a array of let's "N" numbers. we'll all the multiples of the given number "x" 
            if x is prime which means if we multiply with natural numbers. The resultant value will be non-primes. 
                5 x 1 = 5
                5 x 2 = 10
                5 x 3 = 15 
            We'll mark all the values till x X m <= N
            
             
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Problem Understanding:
 * ----------------------
 * We need to find all prime numbers up to a given integer N.
 * A prime number is a number greater than 1 that has no positive divisors
 * other than 1 and itself.
 *
 * Mathematical Insight:
 * ---------------------
 * - A composite number must have at least one factor ≤ √N.
 * - This means when checking for primality, we only need to consider numbers
 *   up to √N as potential factors.
 * - The Sieve of Eratosthenes uses this property to mark all multiples
 *   of each found prime as non-prime.
 *
 * Algorithm:
 * ----------
 * 1. Create a boolean array `isPrime` of size N+1, initialized to true.
 * 2. Mark `isPrime[0]` and `isPrime[1]` as false (0 and 1 are not prime).
 * 3. For each number i from 2 to √N:
 *      - If `isPrime[i]` is true:
 *          - Mark all multiples of i starting from i*i as false
 *            (numbers less than i*i would have been marked already).
 * 4. Collect all indices marked true in `isPrime` — these are the primes.
 *
 * Time Complexity:
 * ----------------
 * O(N log log N) — classic complexity of the Sieve of Eratosthenes.
 *
 * Space Complexity:
 * -----------------
 * O(N) — for storing the boolean array of prime flags.
 */
class Solution {
public:
    vector<int> sieveOfEratosthenes(int N) {
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = isPrime[1] = false;

        int limit = sqrt(N);
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primeNumbers;
        for (int i = 2; i <= N; ++i) {
            if (isPrime[i]) {
                primeNumbers.push_back(i);
            }
        }
        return primeNumbers;
    }
};

int main() {
    Solution obj;
    int N = 20;

    vector<int> primeNumbers = obj.sieveOfEratosthenes(N);

    cout << "Primes up to " << N << ": ";
    for (size_t i = 0; i < primeNumbers.size(); ++i) {
        cout << primeNumbers[i];
        if (i != primeNumbers.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
