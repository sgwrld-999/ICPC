#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Candy
Problem link : https://leetcode.com/problems/candy/
Exaplanation : https://youtube.com/watch?v=IIqVFvKE6RY&list=PLgUwDviBIf0rF1w2Koyh78zafB0cz7tea&index=12
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0; // Edge case: if ratings is empty

        vector<int> left(n), right(n);
        
        // Initialize the first and last values
        left[0] = 1;
        right[n - 1] = 1;

        // Populate the left array (increasing sequence from left to right)
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        // Populate the right array (increasing sequence from right to left)
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }

        // Calculate the total number of candies
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(left[i], right[i]);
        }

        return sum;
    }
};


class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 1;
        int i = 1;
        int peak = 0;
        int downPeak = 0;

        int n = ratings.size();

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum++;
                i++;
            }
            peak = 1;

            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }

            downPeak = 1;

            // This loop should check for ratings[i] < ratings[i-1] to handle descending ratings
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += downPeak;
                downPeak++;
                i++;
            }

            if (downPeak > peak) sum += abs(downPeak - peak);
        }

        return sum;
    }
};