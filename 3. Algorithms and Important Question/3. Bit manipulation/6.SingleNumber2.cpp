#include <bits/stdc++.h>
using namespace std;
/*
Problem name: 137. Single Number II
Problem link: https://leetcode.com/problems/single-number-ii/

Approach 1: Using Hash Map
1. Create a hash map to store the frequency of each number.
2. Traverse the hash map and return the number whose frequency is 1.

Approach 2: Counting bits and dividing with 3 to get the number
1. Traverse the array and count the number of set bits at each position.
2. If the count is not divisible by 3, then set the bit at that position in the answer.
3. Return the answer.

Approach 3: Sorting and Linear Search

Approach 4: Using bucketing
1. Create two variables ones and twos and initialize them to 0.
2. Traverse the array and update ones and twos as follows:
    ones = (ones ^ nums[i]) & ~twos;
    twos = (twos ^ nums[i]) & ~ones;
3. Return ones.

Why working?
1. ones = (ones ^ nums[i]) & ~twos;
    - If the number is already present in ones, then it will be removed by XOR operation.
    - If the number is already present in twos, then it will be removed by AND operation.
    - If the number is not present in ones and twos, then it will be added to ones.
2. twos = (twos ^ nums[i]) & ~ones;
    - If the number is already present in twos, then it will be removed by XOR operation.
    - If the number is already present in ones, then it will be removed by AND operation.
    - If the number is not present in ones and twos, then it will be added to twos.
*/
class Solution {
public:
    //TIme complexity: O(N)
    //Space complecity: O(uniqueNumbers)
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> meiHoMap;

        for(auto it : nums){
            meiHoMap[it]++;
        }

        for(auto it : meiHoMap){
            if(it.second == 1) return it.first;
        }
        return -1;
    }

    //Using Bit Manipulation
    int singleNumber2(vector<int>& nums) {
        int n = nums.size();

        int count = 0 ;
        int ans   = 0 ;

        for(int bitIdx = 0 ; bitIdx < 32 ; bitIdx++){
            count = 0 ;
            for(int j = 0 ; j < n ; j++){
                if(nums[j] & (1 << bitIdx)){
                    count++;
                }
            }
            if(count % 3){
                ans = ans | (1 << bitIdx);
            }
        }

        return ans;
    }
    //Using sorting and linear search
    //Time complexity: O(NlogN + N/3) it's better than the previous one as N X 32 > NlogN As to be logN N should be 2^32 which is not possible.
    int singleNumber3(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        for(int i = 1 ; i < n-1 ; i+= 3){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
        }
        return -1;
    }

    int singleNumber4(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
    
};