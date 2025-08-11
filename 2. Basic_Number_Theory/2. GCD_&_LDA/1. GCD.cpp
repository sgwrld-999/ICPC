#include<bits/stdc++.h>
using namespace std;

/*
Definition: 
    - GCD of two integers a and b is the largest integer that divides both without leaving a remainder.
    - Represented as gcd (a, b)

Example: 
    gcd (12, 8) = 4 because 4 is the largest number dividing both.
Time Complexity: O(log(min(a, b)))

Patterns for GCD:
• Co-prime check: gcd (a, b) = 1 means no common factors.
• LCM relation: lcm (a, b) x gcd (a, b) = a x b.
• Multiple numbers: Reduce sequentially:
gcd (a1, a2, ...,an) = gcd(..gcd (a1, a2), .., an).
• Shifts in bitwise form: If both numbers are even, GCD is at least 2 (Binary GCD optimization).

4. Thinking Framework for CP Problems
    When you see a problem involving:
        • Ratios, scaling, or reducing fractions → GCD is a likely tool.
        • Equal partitioning / grouping → check GCD of group sizes.
        • Synchronization cycles (like meeting times) → often LCM, which depends on GCD.
        • Modular equations — GCD helps in checking solvability.
Steps in CP:
    1. Identify if common factors matter.
    2. Decide between direct GCD computation vs. prime factorization.
    3. Optimize: Euclidean algorithm beats naive factorization.
*/

/*
Refined Statement
    - The Euclidean Algorithm is an efficient method to find the GCD of two integers.

Core property:
The GCD of two numbers doesn't change if we replace the larger number with:
    • The difference between them (subtraction version), or
    • The remainder when the larger is divided by the smaller (modulo version - faster).

Mathematical Forms:
    1. Subtraction form:
        gcd (a, b) = gcd (a - b,b) if a > b
    2. Modulo form (optimized):
        gcd (a, b) = gcd (b, a mod b)
    3. Base case:
        gcd (a, 0) = a

Dry run for substraction: 
    1. Substraction: Called -> gcd(48-18, 18) -> gcd(30, 18) -> Called -> gcd(30-18, 18) -> gcd(12, 18) -> Called -> gcd(12, 18-12) -> gcd(12, 6) -> Called -> gcd(12-6, 6) -> gcd(6, 6) -> Called -> gcd(6, 6-6) -> gcd(6, 0) = 6
    2. Modulo: Called -> gcd(48, 18) -> gcd(18, 48 mod 18) -> gcd(18, 12) -> Called -> gcd(12, 18 mod 12) -> gcd(12, 6) -> Called -> gcd(6, 12 mod 6) -> gcd(6, 0) = 6

Why modulo is better in CP
    • Subtraction may take many steps for large, close numbers.
    • Modulo jumps directly to the remainder, cutting the number down fast.
    • Time complexity: O (log min(a, b)).
*/
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a,int b){
    return (a / gcd(a,b)) * b ;
}
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}
