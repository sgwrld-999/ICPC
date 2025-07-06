#include<iostream>
#include<vector>


/*
Thought Process:

1. The question asks us to check whether a number is an Armstrong number.
2. An Armstrong number is a number that is equal to the sum of its digits each raised to the power of the number of digits.
   For example: 153 is an Armstrong number because 1³ + 5³ + 3³ = 153.
3. To solve this:
   - I’ll first count the number of digits (let’s call it 'order').
   - Then, I’ll extract each digit, raise it to the power of 'order', and add to a sum.
   - Finally, if the sum matches the original number, it is an Armstrong number.

-- I used a helper function to encapsulate the cube sum logic. 
-- I ensured correctness by passing and using parameters correctly.
-- I chose to replace pow() with direct multiplication for cube (small optimization).
*/
class Solution {
  public:
    // Helper function to calculate sum of digits raised to the power 'order'
    int getDigitPowerSum(int num, int order) {
        int sum = 0;
        while(num > 0){
            int rem = num % 10;
            int powered = 1;
            for(int i = 0; i < order; ++i) {
                powered *= rem; // Faster than pow() for small integers
            }
            sum += powered;
            num /= 10;
        }
        return sum;
    }

    /*
    Main function to check if 'n' is an Armstrong number.
    Armstrong number => Sum of each digit raised to number of digits == original number
    */
    bool armstrongNumber(int n) {
        int original = n;
        int order = 0;
        
        // Count digits to find the order
        int temp = n;
        while(temp > 0){
            order++;
            temp /= 10;
        }

        return (getDigitPowerSum(original, order) == original);
    }
};

