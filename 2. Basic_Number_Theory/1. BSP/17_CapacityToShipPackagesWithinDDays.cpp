#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Capacity To Ship Packages Within D Days
Problem link : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
Explanation  : We've to find the minmum weight capacity of the ship to ship all the packages within D days.
               For that we have to check the minimum weight capacity of the ship that can ship all the packages within D days.
Function to calculate the number of days : 
Psuedo Code : 
    1. Initialize dayCtr to 1 and tempSum to 0.
    2. Iterate over the array.
        a. If the sum of current weight and tempSum is greater than the weight capacity, increment dayCtr and reset tempSum to current weight.
        b. Else, add the current weight to tempSum.
    3. Return dayCtr.

Now we are iterating over a RANGFE of weights to find the minimum weight capacity needed to ship all the packages within D days.
Brute force : 
    1. Iterate over the range of weights.
    2. For each weight, calculate the number of days needed to ship all the packages.
    3. If the number of days is less than or equal to D, update the minimum weight capacity.
    4. Return the minimum weight capacity.

Time Complexity : O(N * W * D), where N is the number of packages, W is the maximum weight of a package, and D is the number of days.
Optimized Approach : Why binary search? Range is know and we've to find or search the minimium of weights in the range.
    1. Calculate the total weight and the maximum weight.
    2. Initialize low to the maximum weight and high to the total weight.
    3. While low is less than or equal to high, calculate mid.
    4. Calculate the number of days needed to ship all the packages with the current weight capacity.
    5. If the number of days is less than or equal to D, update high to mid - 1.
    6. Else, update low to mid + 1.
    7. Return low. 

Time Complexity : O(N * log(sum of weights))

*/
class Solution {
public:
    int numOfDays(int arr[], int n, int weight, int days) {
        int dayCtr = 1; // Counter for days
        int tempSum = 0; // Temporary sum for current day's weight
        
        for (int i = 0; i < n; i++) {
            if (arr[i] + tempSum > weight) {
                dayCtr++; // Increment day counter if current weight exceeds capacity
                tempSum = arr[i]; // Reset tempSum for the next day
            } else {
                tempSum += arr[i]; // Add current weight to tempSum
            }
        }
        return dayCtr; // Return the total number of days needed
    }

    int leastWeightCapacity(int arr[], int N, int D) {
        int totalWeight = 0;
        int maxWeight = 0; // Variable to store the maximum weight
        
        for (int i = 0; i < N; i++) {
            totalWeight += arr[i]; // Calculate total weight
            maxWeight = max(maxWeight, arr[i]); // Find the maximum weight
        }
        
        int low = maxWeight; // Initialize low to maxWeight to ensure ship can carry the heaviest item
        int high = totalWeight;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int tempDays = numOfDays(arr, N, mid, D);
            if (tempDays <= D) {
                high = mid - 1; // If it's possible to do it in fewer days, try a lower capacity
            } else {
                low = mid + 1; // If not, increase the capacity
            }
        }
        return low; // Return the minimum capacity needed
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;
        
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}