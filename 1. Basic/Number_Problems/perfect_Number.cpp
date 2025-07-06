#include<iostream>
#include<math>
#include<vector>

/*
Thought Process:

1. We are asked to check whether a number is a "Perfect Number".
   Definition: A perfect number is a positive integer that is equal to the sum of its proper positive divisors, excluding itself.

2. Key observations:
   - We need all divisors less than `num`.
   - For optimization, we only loop till `sqrt(num)`, and for each divisor `i`, we can also include `num / i`.
   - We must avoid adding `num` itself as a divisor.
   - Always remember to handle edge cases like num <= 1.

3. Strategy:
   - Write a helper function `findDivisors` that returns all proper divisors.
   - Sum them and compare with `num`.

4. We choose `vector<int>` to collect divisors and `int` to accumulate the sum.

5. Time Complexity:
   - O(sqrt(n)) for finding divisors.
*/

class Solution {
public:
    // Helper function to find all proper divisors of num (excluding num itself)
    vector<int> findDivisors(int num) {
        vector<int> divs;

        for (int i = 1; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                divs.push_back(i);
                if (i != 1 && i != num / i) {
                    divs.push_back(num / i);
                }
            }
        }

        return divs;
    }

    bool checkPerfectNumber(int num) {
        if (num <= 1) return false; // Edge case: 1 is not a perfect number

        vector<int> divs = findDivisors(num);
        int sum = 0;

        for (auto &it : divs) {
            sum += it;
        }

        return (sum == num);
    }
};

