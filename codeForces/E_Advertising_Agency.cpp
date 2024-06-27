#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
using namespace std;

const int MOD = 1'000'000'007;
const int MAX = 1000;

vector<long long> factorial(MAX + 1); // Stores factorial values
vector<long long> invFactorial(MAX + 1); // Stores inverse factorial values

// Function to perform modular multiplication

long long modMul(long long a, long long b) {
    return (a * b) % MOD;
}

// Function to perform modular exponentiation
long long modPow(long long base, long long exp) {
    if (exp == 0) return 1;
    long long half = modPow(base, exp / 2);
    if (exp % 2 == 0) return modMul(half, half);
    return modMul(modMul(half, half), base);
}

// Function to precompute factorials and inverse factorials
void precomputeFactorials() {
    factorial[0] = invFactorial[0] = 1;
    for (int i = 1; i <= MAX; ++i) {
        factorial[i] = modMul(factorial[i - 1], i);
        invFactorial[i] = modPow(factorial[i], MOD - 2);
    }
}

// Function to calculate the combination (n choose k)
long long combination(int n, int k) {
    if (k > n) return 0;
    return modMul(factorial[n], modMul(invFactorial[k], invFactorial[n - k]));
}

// Function to shuffle and sort the elements of a vector
void shuffleAndSort(vector<int>& arr) {
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);
    sort(arr.begin(), arr.end());
}

int main() {
    precomputeFactorials(); // Precompute factorials and inverse factorials

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int numElements, numChosen;
        cin >> numElements >> numChosen;

        vector<int> elements(numElements);
        for (int& element : elements) cin >> element;

        shuffleAndSort(elements); // Shuffle and sort the elements

        int maxElement = *max_element(elements.begin(), elements.end());
        vector<int> elementCount(maxElement + 1, 0); // Stores the count of each element
        vector<int> chosenCount(maxElement + 1, 0); // Stores the count of chosen elements

        // Count the occurrences of chosen elements
        for (int i = numElements - 1; i >= numElements - numChosen; --i) {
            chosenCount[elements[i]]++;
        }

        // Count the occurrences of all elements
        for (int element : elements) {
            elementCount[element]++;
        }

        long long result = 1;

        // Calculate the result using combinations
        for (int i = 1; i <= maxElement; ++i) {
            if (chosenCount[i] > 0) {
                result = modMul(result, combination(elementCount[i], chosenCount[i]));
            }
        }

        cout << result << endl; // Output the result
    }

    return 0;
}
