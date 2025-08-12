#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

/*
Problem Link: https://leetcode.com/problems/closest-prime-numbers-in-range/
Wiki: https://en.wikipedia.org/wiki/Prime_number
*/
/*
 * Problem Understanding:
 * ----------------------
 * We need to find the closest pair of prime numbers in a given range [left, right].
 * If there are fewer than two primes in that range, return {-1, -1}.
 *
 * Mathematical Insight:
 * ---------------------
 * - To check primality for multiple numbers efficiently, use the Sieve of Eratosthenes.
 * - The sieve marks multiples of primes as non-prime.
 * - The closest pair will always be adjacent primes in the sorted list of primes in range.
 *
 * Algorithm:
 * ----------
 * 1. Generate all prime numbers up to 'right' using the sieve.
 * 2. Store primes that fall within the range [left, right].
 * 3. If fewer than two primes, return {-1, -1}.
 * 4. Iterate through adjacent primes to find the pair with the smallest difference.
 * 5. Return that pair.
 *
 * Time Complexity:
 * ----------------
 * O(n log log n) for sieve, where n = right.
 *
 * Space Complexity:
 * -----------------
 * O(n) for storing primality flags.
 */
class Solution {
public:
    vector<int> generatePrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        int limit = sqrt(n);
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = generatePrimes(right);

        // Filter primes in the given range
        vector<int> primesInRange;
        for (int p : primes) {
            if (p >= left && p <= right) {
                primesInRange.push_back(p);
            }
        }

        if (primesInRange.size() < 2) {
            return {-1, -1};
        }

        // Find closest adjacent primes
        vector<int> ans(2);
        int minDiff = INT_MAX;
        for (int i = 0; i < (int)primesInRange.size() - 1; i++) {
            int diff = primesInRange[i+1] - primesInRange[i];
            if (diff < minDiff) {
                minDiff = diff;
                ans = {primesInRange[i], primesInRange[i+1]};
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int left = 10, right = 50;
    vector<int> result = sol.closestPrimes(left, right);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
