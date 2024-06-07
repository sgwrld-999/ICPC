#include <climits> // For INT_MAX and INT_MIN
#include <cstdlib> // For abs()
/*
Problem name: 29. Divide Two Integers
Problem link: https://leetcode.com/problems/divide-two-integers/

Approach 1: Repeated Subtraction

1. Handle special cases:
    - If the divisor is 0, return INT_MAX.
    - If the dividend is 0, return 0.
    - If the divisor is 1, return the dividend.
    - If the divisor is -1, return the negation of the dividend.
2. Determine the sign of the result by XORing the signs of the dividend and divisor.
3. Use long long to avoid overflow issues.
4. Perform the division using bit manipulation:
    - Initialize the result to 0.
    - While the dividend is greater than or equal to the divisor:
        - Find the largest multiple of the divisor that can be subtracted from the dividend.
        - Update the result by adding the count of the multiple.
        - Subtract the multiple from the dividend.
5. Apply the sign to the result.
6. Handle overflow by clamping the result to INT_MAX or INT_MIN.
7. Return the result as an integer.

Intitution:
We can write any number in terms of powers of 2.
For example, 19 = 16 + 2 + 1 = 2^4 + 2^1 + 2^0
So, we can write the dividend in terms of powers of 2 and then subtract the divisor from it.
We can keep on subtracting the divisor from the dividend until the dividend is greater than the divisor.
The number of times we subtract the divisor will be the quotient.
Let's take an example: 
dividend = 19, divisor = 3
22 = 3 * 7 = 3 * (2^2 + 2^1 + 2^0) 
We'll remove the biggest number possible from the dividend.
19 - 12 = 7
7 - 6 = 1
1 - 1 = 0
So, the quotient is 7.

*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle special cases
        if (divisor == 0) return INT_MAX; // Division by zero
        if (dividend == 0) return 0; // 0 divided by any number is 0
        if (divisor == 1) return dividend; // Division by 1
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX; // Prevent overflow
            return -dividend; // Division by -1
        }

        // Determine the sign of the result
        bool sign = (dividend > 0) ^ (divisor > 0);

        // Use long long to avoid overflow issues
        long long n = labs(dividend);
        long long d = labs(divisor);
        long long ans = 0;

        // Perform the division using bit manipulation
        while (n >= d) {
            long long temp = d, count = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            ans += count;
            n -= temp;
        }

        // Apply the sign to the result
        if (sign) ans = -ans;

        // Handle overflow by clamping to INT_MAX or INT_MIN
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};
