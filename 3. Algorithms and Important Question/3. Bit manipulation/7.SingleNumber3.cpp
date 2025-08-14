#include<bits/stdc++.h>
using namespace std;
/*
Problem name: 260. Single Number III
Problem link: https://leetcode.com/problems/single-number-iii/

Approach 1: Using Hash Map
1. Create a hash map to store the frequency of each number. 
2. Traverse the hash map and return the number whose frequency is 1.

Approach 2: Using the concepts of bucketing
1. Find the XOR of all the numbers.
2. Find the rightmost set bit in the XOR result.
3. Divide the numbers into two groups based on the rightmost set bit.
4. Find the XOR of the two groups and return the result.

In this approach we can find the rightmost set bit using the following formula:
1. rightmostSetBit = (result) & (-result) ;
2. (result&(result-1))^result

Both the above formulas will give the rightmost set bit.
Reason:
Let's take an example to illustrate how both expressions work to isolate the lowest set bit of a number. We'll use the number 18 (binary representation: `10010`) as `result` for this dry run.

### Expression 1: `long long setBit = (result) & (-result);`

1. **Calculate `-result`**:
   - `result = 18` (binary: `10010`)
   - To find `-result`, first invert the bits of `result`: `01101`
   - Add 1 to the least significant bit: `01101 + 1 = 01110` (binary for -18)

2. **AND `result` with `-result`**:
   - `result = 10010`
   - `-result = 01110`
   - Perform AND operation: `10010 & 01110 = 00010`

The result `00010` (binary) represents the number 2, which is the lowest set bit in the original number 18.

### Expression 2: `long long setBit = (result & (result - 1)) ^ result;`

1. **Calculate `result - 1`**:
   - `result = 18` (binary: `10010`)
   - `result - 1 = 17` (binary: `10001`)

2. **AND `result` with `result - 1`**:
   - `result = 10010`
   - `result - 1 = 10001`
   - Perform AND operation: `10010 & 10001 = 10000`

3. **XOR the result of the AND operation with `result`**:
   - `AND result = 10000`
   - `result = 10010`
   - Perform XOR operation: `10000 ^ 10010 = 00010`

The result `00010` (binary) again represents the number 2, which is the lowest set bit in the original number 18.

### Summary
Both expressions isolate the lowest set bit (rightmost set bit) of the number. The first method uses the properties of two's complement and a simple AND operation to directly isolate this bit. The second method first clears the lowest set bit by subtracting 1 and then uses XOR to highlight the difference between the original number and the modified number, effectively isolating the same lowest set bit. Both yield the same result, demonstrating their equivalence in functionality.


*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int result = 0 ;
        for(int it : nums){
            result ^= it;
        }

        long long setBit = (result) & (-result) ;
        // long long setBit = (result&(result-1))^result ;

        int grpA = 0 ;
        int grpB = 0 ;

        for(auto it : nums){
            if(it & setBit){
                grpA ^= it;
            }else{
                grpB ^= it;
            }
        }

        return {grpA,grpB};
    }
};