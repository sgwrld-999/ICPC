#include <bits/stdc++.h>
using namespace std;
/*
Problem name : Minimum Number of Days to Make m Bouquets
Problem link : https://practice.geeksforgeeks.org/problems/0b1f6
Explanation : Given an integer array bloomDay, an integer m for number of bouquets, and an integer k adjacent flowers. We need to find the minimum number of days to make m bouquets such that each bouquet contains exactly k flowers.
Lets understand with an example : 
M = 2, K = 3
bloomDay = [5, 5, 5, 5, 10, 5, 5]
We can make 2 bouquets with 3 flowers in each bouquet. We can make the bouquets in 10 days.
How lets see the process :
day 1 : [NB,NB,NB,NB,NB,NB,NB] -> No bouquet possible
day 2 : [NB,NB,NB,NB,NB,NB,NB] -> No bouquet possible
day 3 : [NB,NB,NB,NB,NB,NB,NB] -> No bouquet possible
day 4 : [NB,NB,NB,NB,NB,NB,NB] -> No bouquet possible
day 5 : [B,B,B,B,NB,B,B] -> 1 bouquet possible as [0,1,2] or [1,2,3] 
day 6 : [B,B,B,B,NB,B,B] -> 1 bouquet possible 
day 7 : [B,B,B,B,NB,B,B] -> 1 bouquet possible
day 8 : [B,B,B,B,NB,B,B] -> 1 bouquet possible
day 9 : [B,B,B,B,NB,B,B] -> 1 bouquet possible
day 10 : [B,B,B,B,B,B,B] -> 2 bouquet possible as [0,1,2] and [4,5,6]

So, the answer is 10.

Now the code for the function which will tell if it's possible to make m bouquets with k flowers in each bouquet in given days or not.

Psuedo code :
1. Intialize count = 0, bouquets = 0
2. Iterate over the bloomDay array
   i. If the bloomDay is less than or equal to the given day, increment the count
   ii. Else, calculate the number of bouquets possible with the count and k. Add the number of bouquets that is possible to the bouquets by that number and reset the count to 0.
3. Calculate the number of bouquets possible with the remaining count and k. Add the number of bouquets that is possible to the bouquets.
4. Return if the number of bouquets is greater than or equal to m.

Now, we can use the above function to find the minimum number of days to make m bouquets with k flowers in each bouquet.

For the searching part we've to define the range of the days. The minimum day will be the minimum bloomDay and the maximum day will be the maximum bloomDay. We can then apply binary search to find the minimum number of days to make m bouquets with k flowers in each bouquet.
Brute force : We can iterate over the range of days from minDay to maxDay and check if it's possible to make m bouquets with k flowers in each bouquet. We can return the minimum day that satisfies the condition.
Time complexity : O(n*(max(bloomDay) - min(bloomDay))) where n is the size of the bloomDay array.

Optimized approach : Binary search as we've to find the minimum from a given range of values.
We can find the minimum and maximum values of the range of days. We can then apply binary search to find the minimum number of days to make m bouquets with k flowers in each bouquet.
Time complexity : O(n*log(max(bloomDay) - min(bloomDay))) where n is the size of the bloomDay array.

*/
class Solution {
public:
    bool canHarvest(int m, int k, vector<int>& bloomDay, int day) {
        int count = 0;
        int bouquets = 0;
        for (auto bloom : bloomDay) {
            if (bloom <= day) {
                count++;
            } else {
                bouquets += (count / k);
                count = 0;
            }
        }
        bouquets += (count / k);
        return (bouquets >= m);
    }

    int minDaysToHarvest(int M, int K, vector<int>& bloomDay) {
        int requiredFlowers = M * K;
        if (requiredFlowers > bloomDay.size()) return -1;
        
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int low = minDay;
        int high = maxDay;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (!canHarvest(M, K, bloomDay, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
        cin >> m >> k;
        string s;
        getline(cin, s);
        getline(cin, s);
        int n = s.length();
        int num = 0;
        bool f = false;
        vector<int> bloomDay;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!f)
                    continue;
                bloomDay.push_back(num);
                num = 0;
                f = false;
            } else {
                num = (num * 10) + (s[i] - '0');
                f = true;
            }
        }
        if (f) {
            bloomDay.push_back(num);
        }
        Solution obj;
        cout << obj.minDaysToHarvest(m, k, bloomDay) << endl;
    }
    return 0;
}
