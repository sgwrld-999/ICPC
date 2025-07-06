#include<iostream>
#include<vector>


#include <iostream>
using namespace std;

/**
 * Thought Process:
 * - An Automorphic number is a number whose square ends with the same digits as the number itself.
 * - So I will:
 *   - Square the number.
 *   - Count the number of digits in the original number.
 *   - Extract the last `d` digits from the square using modulus `10^d`.
 *   - Compare it with the original number.
 */

class Solution {
public:

    // Function to count the number of digits in a number
    int countDigits(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }

    // Function to check if a number is Automorphic
    bool isAutomorphic(int num) {
        int square = num * num;
        int digits = countDigits(num);

        int mod = 1;
        for (int i = 0; i < digits; ++i) {
            mod *= 10;
        }

        return (square % mod == num);
    }
};

// Sample usage for testing
int main() {
    Solution sol;
    int num = 76; // Known automorphic number: 76^2 = 5776, ends in 76
    if (sol.isAutomorphic(num))
        cout << num << " is an Automorphic Number\n";
    else
        cout << num << " is NOT an Automorphic Number\n";

    return 0;
}

