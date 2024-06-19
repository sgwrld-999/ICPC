#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Search in Rotated Sorted Array a
Problem link : https://leetcode.com/problems/search-in-rotated-sorted-array/
Explanation  : We are given an integer array nums sorted in ascending order, and an integer target.
               Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
               (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
               You should search for target in nums and if you found the target in the array return its index, otherwise return -1.
               We can use binary search to solve this problem.
               How? By using the property of the sorted array.
               For sorted array for every i < j , nums[i] < nums[j](Increasing order) or nums[i] > nums[j](Decreasing order)
               So, we can use this property to find the target element.
               Rest explanation is in the code.               
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid]==target) return mid; // If the mid element is the target element then return the index
            else if(nums[low]<=nums[mid]){ // If the left half is sorted then check if the target element is in the left half or not
                if(nums[low] <= target && nums[mid] >= target) high = mid - 1; // If the target element is in the left half then eleminate the right half
                else low = mid + 1; // If the target element is not in the left half then eleminate the left half
            }else{ // If the right half is sorted then check if the target element is in the right half or not
                if(nums[mid] <= target && nums[high] >= target) low = mid + 1; // If the target element is in the right half then eleminate the left half
                else high = mid - 1;// If the target element is not in the right half then eleminate the right half
            }
        }

        return -1;// If the target element is not found then return -1
    }
};

int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    Solution solution; 
    int target;
    cin >> target;
    int result = solution.search(ipVec, target); 
    cout << "Required Element ans :  [" << result << "]"<< endl;
    return 0;
}
