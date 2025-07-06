#include<iostream>
#include<vector>

/*
1. First, I try to understand what’s being asked:
We need to check whether a given integer is a palindrome or not.

A palindrome number is one that reads the same forwards and backwards, like 121, 1221, or 7.
_______________________________________________________________________________________________
2. Let me consider some edge cases:
Negative numbers like -121 can't be palindromes because of the - sign.

Any number ending in 0 (except 0 itself) can't be a palindrome either — for example, 10 reversed is 01, which is not valid.
______________________________________________________________________________________________
3. Now I think about approaches:

Brute Force:
Convert the number to a string, reverse it, and compare.

It’s easy, but involves extra space for the string.

Optimal approach:
Reverse half of the number as an integer and compare with the other half.

This avoids integer overflow and uses O(1) space.

This approach is used in industry to write efficient and safe code.
_____________________________________________________________________________________________
4. Algorithm:
Keep extracting the last digit and build the reversed number.

Stop when the reversed half becomes equal to or greater than the original half.

Compare both halves.
______________________________________________________________________________________________


*/

#include <iostream>
using namespace std;

/*
🧠 Thought Process:
- Check if number is negative or ends in 0 (but isn't 0 itself) — these can't be palindromes.
- Reverse half of the digits, and compare the two halves.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // ❗ Negative numbers and numbers ending in 0 (but not 0) can't be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;

        // 🔁 Keep reversing the last digit until we reach the halfway point
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // ✅ If even number of digits, both halves should be equal
        // ✅ If odd number of digits, ignore the middle digit in reversedHalf (using /10)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

/*
Final Notes (to the interviewer):
Time Complexity: O(log₁₀N) — since we only process half the digits.

Space Complexity: O(1) — no extra space used.

Clean, safe from overflow, and avoids string conversion.
*/
