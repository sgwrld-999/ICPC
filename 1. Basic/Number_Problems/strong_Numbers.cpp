#include<iostream>
#include<vectors>

#include <iostream>
#include <vector>
using namespace std;

/**
 * Thought Process:
 * - I know a Strong number is one where the sum of the factorials of its digits equals the number itself.
 * - Since factorials of digits 0–9 are reused, I will precompute them for efficiency.
 * - The function will iterate through each digit of the number, add the factorial to a sum,
 *   and compare the result with the original number.
 */

class Solution {
public:

    // Helper function to precompute factorials of digits 0–9
    void preComputeFact(vector<int>& preCompFact) {
        preCompFact[0] = preCompFact[1] = 1;
        int fact = 1;
        for (int i = 2; i <= 9; i++) {
            fact *= i;
            preCompFact[i] = fact;
        }
    }

    // Function to check if a number is a Strong number
    bool strongNumber(int num) {
        vector<int> vectFact(10);
        preComputeFact(vectFact);

        int temp = num;
        int sum = 0;

        while (temp > 0) {
            sum += vectFact[temp % 10];
            temp /= 10;
        }

        return sum == num;
    }
};

// Sample usage for testing
int main() {
    Solution sol;
    int num = 145; // Known strong number: 1! + 4! + 5! = 145
    if (sol.strongNumber(num))
        cout << num << " is a Strong Number\n";
    else
        cout << num << " is NOT a Strong Number\n";

    return 0;
}

