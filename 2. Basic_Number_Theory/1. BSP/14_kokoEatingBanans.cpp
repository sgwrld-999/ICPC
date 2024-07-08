#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Koko Eating Bananas
Problem link : https://leetcode.com/problems/koko-eating-bananas/description/
Explanation : Koko loves to eat bananas. There are N piles of bananas, the i-th pile has piles[i] bananas. The guards have gone and will come back in H hours.
Koko can decide her bananas-per-hour eating speed of K. Each hour, she chooses some pile of bananas and eats K bananas from that pile. If the pile has less than K bananas, she eats all of them instead and will not eat any more bananas during this hour.

According to the problem, Koko wants to eat all the bananas in the least number of hours. Return the minimum integer K such that she can eat all the bananas within H hours.
Brute force approach : We can iterate over all the possible values of K from 1 to max(piles) and calculate the total hours required to eat all the bananas. We can return the minimum K such that the total hours are less than or equal to H.
Why max(piles)? Because we've to find the minimum. We can iterate over the range of 1 to infinity but that will not gonna do any good.
So, limiting the range to max(piles) will help us to find the minimum in the least time.
Time complexity : O(n*max(piles)) where n is the size of the piles array.

Optimized approach : Binary search as we've to find the minimum from a given range of values. 
We can find the minimum and maximum values of the range of K. We can then apply binary search to find the minimum K such that the total hours are less than or equal to H.
Time complexity : O(n*log(max(piles))) where n is the size of the piles array.

NOTE1 : ceil() function is used to round up the value to the nearest integer.So we've to use the double to avoid flooring the value by int.
NOTE2 : The total hours are calculated by dividing the pile by the bananas per hour and then rounding up the value to the nearest integer. If the values is not exactly divisible, we've to eat the remaining bananas in the next hour. a
and if the bananas are less than the bananas per hour, we take the ceil of the division.

Example : piles = [3,6,7,11], H = 8
            total hours for K = 4 : 1 + 2 + 2 + 3 = 8 as 3/4 = 1, 6/4 = 2, 7/4 = 2, 11/4 = 3
            
*/
class Solution {
public:
    int calculateTotalHours(vector<int>& piles, int bananasPerHour) {
        int totalHours = 0;
        for (auto pile : piles) {
            totalHours += ceil((double)pile / (double)bananasPerHour);
        }
        return totalHours;
    }

    int findMinBananasPerHour(int N, vector<int>& piles, int H) {
        int maxPile = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = maxPile;
        int totalHours = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            totalHours = calculateTotalHours(piles, mid);

            if (totalHours <= H) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> piles;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            piles.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.findMinBananasPerHour(n, piles, h);
        cout << "\n";
    }
    return 0;
}
/*
Test cases: 
Input :
2
4
3 6 7 11
8
5
30 11 23 4 20
6
Output :
4
23

*/