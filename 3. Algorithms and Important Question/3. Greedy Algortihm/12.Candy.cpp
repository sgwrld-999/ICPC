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