#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Find the Smallest Divisor Given a Threshold
Problem link : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
Explanantion : We've to find the smallest divisor such that the sum of the array elements divided by the divisor is less than or equal to the target sum.
               As question stated we've to take ceil of the division of array elements and divisor.
               So, we can't directly divide the sum of array elements by divisor and compare it with target sum.
               We've to define the range of the divisor, which is from 1 to maximum element of the array.
               Why maximum element of the array? Because if we take divisor greater than the maximum element of the array, then the sum of the array elements divided by the divisor will be 1. 
               And we've to find the smallest divisor. Limiting the range of the divisor will help us to reduce the time complexity.
               Example : 
                nums = [1, 2, 5, 9], targetSum = 6
                Here, the range of the divisor is from 1 to 9.
                For divisor = 1 -> ceil(1/1) + ceil(2/1) + ceil(5/1) + ceil(9/1) = 1 + 2 + 5 + 9 = 17
                For divisor = 2 -> ceil(1/2) + ceil(2/2) + ceil(5/2) + ceil(9/2) = 1 + 1 + 3 + 5 = 10
                For divisor = 3 -> ceil(1/3) + ceil(2/3) + ceil(5/3) + ceil(9/3) = 1 + 1 + 2 + 3 = 7
                For divisor = 4 -> ceil(1/4) + ceil(2/4) + ceil(5/4) + ceil(9/4) = 1 + 1 + 2 + 3 = 7
                For divisor = 5 -> ceil(1/5) + ceil(2/5) + ceil(5/5) + ceil(9/5) = 1 + 1 + 1 + 2 = 5
                For divisor = 6 -> ceil(1/6) + ceil(2/6) + ceil(5/6) + ceil(9/6) = 1 + 1 + 1 + 2 = 5
                For divisor = 7 -> ceil(1/7) + ceil(2/7) + ceil(5/7) + ceil(9/7) = 1 + 1 + 1 + 2 = 5
                For divisor = 8 -> ceil(1/8) + ceil(2/8) + ceil(5/8) + ceil(9/8) = 1 + 1 + 1 + 2 = 5
                For divisor = 9 -> ceil(1/9) + ceil(2/9) + ceil(5/9) + ceil(9/9) = 1 + 1 + 1 + 1 = 4
                So, the smallest divisor is 5.
                So, the brute force is to iterate from 1 to maximum element of the array and calculate the sum of the array elements divided by the divisor.
                But, this will take O(n*n) time complexity.

                How can we optimize this?Looking carefully we can see that we've a range of the divisor and we've to find the smallest divisor.
                So, we can use binary search to find the smallest divisor, as if let's we selected 6 as the divisor and the sum of the array elements divided by 6 is 5.
                Then our answer may or may not be 6. It can be less than 6. So, we can use binary search to find the smallest divisor as we'll trim half search space. and look for the other side.
                So, the time complexity will be O(nlog(maxElement)).

*/
class Solution {
public:
    int sumOfCeilDivisions(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / (double)divisor);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int targetSum) {
        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());
        
        int low = 1; 
        int high = maxElement; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = sumOfCeilDivisions(nums, mid);
            
            if (sum <= targetSum) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, targetSum;
        cin >> n >> targetSum;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution obj;
        cout << obj.smallestDivisor(nums, targetSum) << endl;
    }

    return 0;
}
