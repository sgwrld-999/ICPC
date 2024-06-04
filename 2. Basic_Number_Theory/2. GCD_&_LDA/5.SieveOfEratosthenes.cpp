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
class Solution{
    public:
    vector<int> sieveOfEratosthenes(int N) {
        vector<int> prime(N + 1, 1);

        prime[0] = prime[1] = 0 ; // 0 and 1 are not prime numbers
        int sqrtN = sqrt(N);
        for(int i = 2 ; i < sqrtN ; i++) // checking from 2 to sqrt(n)  -> Why we are checking till sqrt(n) only? Because if we go beyond the sqrt(n) then the number will go beyond n and we already have checked the number till n.
        {
            if(prime[i] == 1)
            {
                for(int j = i * 2 ; j <= N ; j+= i){ //Why j += i? Because at every iteration we are marking the multiples of i as false so we are incrementing the value of j by i. example 5 * 2 = 10 -> 5 + 5 * 2 = 10 + 5 = 15
                    prime[j] = 0;
                }
            }
        }

        vector<int> primeNumbers;
        for(int i = 0 ;i < N ; i++){
            if(prime[i] == 1){
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
    for(int i = 0 ; i < primeNumbers.size() ; i++){
        cout << primeNumbers[i] << " ";
    }
    return 0;
}