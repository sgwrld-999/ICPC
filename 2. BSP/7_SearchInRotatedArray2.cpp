#include <bits/stdc++.h>
using namespace std;
/*
Problem : Search in Rotated Sorted Array II or Search in Rotated Sorted Array with Duplicates
Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
Explanation : We are given an integer array nums sorted in non-decreasing order, and an integer target.
              We need to search for target in nums and if we found the target in the array return its index, otherwise return -1.
              The array may contain duplicates.
              We can use binary search to solve this problem.
              How? By using the property of the sorted array.
              For sorted array for every i < j , nums[i] < nums[j] or nums[i](Increasing order) > nums[j](Decreasing order)
              So, we can use this property to find the target element but there is a catch let's understand with an example.
              Example : [3,3,1,3,3,3,3] and target = 1 -> If we apply the above logic then we will get the answer as -1 but the answer is 2. Why so?
              low = 0, high = 6, mid = 3, nums[mid] = 3, nums[low] = 3, nums[high] = 3, nums[low] == nums[mid] == nums[high] Now which half to eleminate? We can't decide.
              So instead of eleminating the half we will trim down the search space by decrementing high and incrementing low and restarting the loop.
              Rest explanation is in the code.               

*/
class MySolution {
public:
    int SearchInRotatedArrayWithDuplicates(std::vector<int>& ipVec, int low, int high, int target) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            //The loop below is used to trim down the search space by decrementing high and incrementing low and restarting the loop.
            // If the low, mid and high are same then we can't decide which half to eleminate so we will trim down the search space by decrementing high and incrementing low and restarting the loop.
            while ((low < mid && ipVec[low] == ipVec[mid]) && (mid < high && ipVec[mid] == ipVec[high])) {
                low++;
                high--;
            }
            if (ipVec[mid] == target) {
                ans = mid;
                break;
            }
            if (ipVec[low] <= ipVec[mid]) {
                if (ipVec[low] <= target && target <= ipVec[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (ipVec[mid] <= target && target <= ipVec[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        std::cin >> ipVec[i];
    }
    MySolution solution;
    int target;
    std::cin >> target;
    int result = solution.SearchInRotatedArrayWithDuplicates(ipVec, 0, sizeOfIpVec - 1, target);
    std::cout << "Required Element ans: [" << result << "]" << std::endl;
    return 0;
}
