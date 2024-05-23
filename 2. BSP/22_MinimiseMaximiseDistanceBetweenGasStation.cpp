#include <bits/stdc++.h>
#include <queue> // Add missing include directive

using namespace std;
/*
Problem name : Minimise the maximum distance between gas stations
Problem link : https://leetcode.com/problems/minimize-max-distance-to-gas-station/
Explanation  : In this problem, we are given an array of gas stations and we have to place k gas stations in such a way that the maximum distance between any two gas stations is minimized. We have to return the minimum possible maximum distance between any two gas stations.
               For this problem we can place any where in the segment between two gas statios or before the 1st or last gas station.
               For example : N = 5, arr[] = {1,2,3,4,5}, k = 4
               we can place the gas station ar 0.5 or 6 both are valid.But as question is asking to minimise the maximum distance between gas stations we will place the gas station between the starting and ending gas station.
               For the above example the answer will be 0.5 as One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this.

Approach1 : For this  we'll find the maximum section length between two gas stations and place the gas station in that segment and increment the count of gas station in that segment. We'll repeat this process for k gas stations and then we'll find the maximum section length between two gas stations and return that as the answer.
            Time complexity : O(n*k)
            Space complexity : O(n)
Dry run example for quadtratic solution: 
Start
  |
  V
Initialize:
  n = 5
  howMany = {0, 0, 0, 0}
  |
  V
For gasStations = 1 to k (k = 4):
  |
  V
  Find segment with maximum section length:
    maxSection = -1, maxInd = -1
    Loop through segments (i = 0 to n-2):
      - Segment 0 (1-2):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: maxSection = 1, maxInd = 0
      - Segment 1 (2-3):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: (no change)
      - Segment 2 (3-4):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: (no change)
      - Segment 3 (4-5):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: (no change)
  |
  V
  Increment howMany[maxInd] (maxInd = 0):
    howMany = {1, 0, 0, 0}
  |
  V
  Repeat for next gas station:
  |
  V
  Find segment with maximum section length:
    maxSection = -1, maxInd = -1
    Loop through segments (i = 0 to n-2):
      - Segment 0 (1-2):
        diff = 1, sectionLength = 1 / (1 + 1) = 0.5
        if sectionLength > maxSection: maxSection = 0.5, maxInd = 0
      - Segment 1 (2-3):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: maxSection = 1, maxInd = 1
      - Segment 2 (3-4):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: (no change)
      - Segment 3 (4-5):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: (no change)
  |
  V
  Increment howMany[maxInd] (maxInd = 1):
    howMany = {1, 1, 0, 0}
  |
  V
  Repeat for next gas station:
  |
  V
  Find segment with maximum section length:
    maxSection = -1, maxInd = -1
    Loop through segments (i = 0 to n-2):
      - Segment 0 (1-2):
        diff = 1, sectionLength = 1 / (1 + 1) = 0.5
        if sectionLength > maxSection: maxSection = 0.5, maxInd = 0
      - Segment 1 (2-3):
        diff = 1, sectionLength = 1 / (1 + 1) = 0.5
        if sectionLength > maxSection: (no change)
      - Segment 2 (3-4):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: maxSection = 1, maxInd = 2
      - Segment 3 (4-5):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: (no change)
  |
  V
  Increment howMany[maxInd] (maxInd = 2):
    howMany = {1, 1, 1, 0}
  |
  V
  Repeat for next gas station:
  |
  V
  Find segment with maximum section length:
    maxSection = -1, maxInd = -1
    Loop through segments (i = 0 to n-2):
      - Segment 0 (1-2):
        diff = 1, sectionLength = 1 / (1 + 1) = 0.5
        if sectionLength > maxSection: maxSection = 0.5, maxInd = 0
      - Segment 1 (2-3):
        diff = 1, sectionLength = 1 / (1 + 1) = 0.5
        if sectionLength > maxSection: (no change)
      - Segment 2 (3-4):
        diff = 1, sectionLength = 1 / (1 + 1) = 0.5
        if sectionLength > maxSection: (no change)
      - Segment 3 (4-5):
        diff = 1, sectionLength = 1 / (0 + 1) = 1
        if sectionLength > maxSection: maxSection = 1, maxInd = 3
  |
  V
  Increment howMany[maxInd] (maxInd = 3):
    howMany = {1, 1, 1, 1}
  |
  V
End of gas station placement
  |
  V
Calculate the maximum section length:
  maxAns = -1
  Loop through segments (i = 0 to n-2):
    - Segment 0 (1-2):
      sectionLength = 1 / (1 + 1) = 0.5
      if sectionLength > maxAns: maxAns = 0.5
    - Segment 1 (2-3):
      sectionLength = 1 / (1 + 1) = 0.5
      if sectionLength > maxAns: (no change)
    - Segment 2 (3-4):
      sectionLength = 1 / (1 + 1) = 0.5
      if sectionLength > maxAns: (no change)
    - Segment 3 (4-5):
      sectionLength = 1 / (1 + 1) = 0.5
      if sectionLength > maxAns: (no change)
  |
  V
Return maxAns (maxAns = 0.5)
  |
  V
Print "The answer is: 0.5"
  |
  V
End

Approach2 : We can use a max heap to store the segments and their section length. We'll find the segment with the maximum section length and place the gas station in that segment and increment the count of gas station in that segment. We'll repeat this process for k gas stations and then we'll find the maximum section length between two gas stations and return that as the answer.
            Time complexity : O(n*log(n) + k*log(n))
            Space complexity : O(n)

Dry run example for heap solution:
[Start]
    |
    v
[Initialize variables: n=4 (stations), k=2 (new stations), pq (priority queue)]
    |
    v
[Calculate initial sections and push to pq]
    |-> Distances: 5-1=4, 8-5=3, 10-8=2
    |-> pq: {4,0}, {3,1}, {2,2} (Format: {distance, index})
    |
    v
[Place 1st gas station (k=1)]
    |-> Pop top of pq: {4,0} (longest section between 1 and 5)
    |-> Increment howMany for this section: howMany[0] = 1
    |-> Recalculate new section length: 4 / (1 + 1) = 2
    |-> Push {2,0} back to pq
    |-> pq now: {3,1}, {2,2}, {2,0}
    |
    v
[Place 2nd gas station (k=2)]
    |-> Pop top of pq: {3,1} (longest section between 5 and 8)
    |-> Increment howMany for this section: howMany[1] = 1
    |-> Recalculate new section length: 3 / (1 + 1) = 1.5
    |-> Push {1.5,1} back to pq
    |-> pq now: {2,2}, {2,0}, {1.5,1}
    |
    v
[After placing 2 gas stations, top of pq is minimized max distance]
    |-> pq top: {2,2} (meaning the longest distance between any two stations is now 2)
    |
    v
[Return top of pq as result: 2]
    |
    v
[End]

Approach3 : We can use binary search to find the minimum possible maximum distance between any two gas stations. We'll start with a low value of 0 and a high value of the maximum distance between any two gas stations. We'll calculate the mid value and check if it is possible to place k gas stations such that the maximum distance between any two gas stations is less than or equal to mid. If it is possible, we'll update the high value to mid, else we'll update the low value to mid. We'll repeat this process until the low value is less than the high value. Finally, we'll return the high value as the answer.
            Time complexity : O(n*log(maxDist))
            Space complexity : O(1)

            For this approach we need to define the range.
            And the range will be from 0 to the maximum distance between any two gas stations.
            Why 0 to maximum distance between any two gas stations?
            For 0 it's not mention that we can not place the gas station at the same place means we can place it.
            And for the maximum distance because we've to minimize the maximum distance between any two gas stations.
            Few things to modify in the binary search approach:
            1. while(low < high) to while(high - low > 1e-6) : This is because we are dealing with double values and we need to check the difference between low and high.
            2. low = mid to low = mid  : This is because we need to move the low value to the mid value. And the value is double so we can't use low = mid + 1 as it will skip the mid values.
            3. high = mid to high = mid : This is because we need to move the high value to the mid value. And the value is double so we can't use high = mid - 1 as it will skip the mid values.

Dry run example for binary search solution:
Start
  |
  V
Initialize:
  n = stations.size() = 5
  low = 0
  high = 0
  |
  V
Calculate initial high value:
  For i = 0 to n-2:
    high = max(high, (stations[i+1] - stations[i]))
    - i = 0: high = max(0, 1) = 1
    - i = 1: high = max(1, 1) = 1
    - i = 2: high = max(1, 1) = 1
    - i = 3: high = max(1, 1) = 1
  high = 1
  |
  V
Set precision:
  diff = 1e-6
  |
  V
While (high - low > diff):
  |
  V
  Calculate mid:
    mid = (low + high) / 2.0 = (0 + 1) / 2.0 = 0.5
  |
  V
  Call numberOfGasStationsRequired(mid, stations):
    Initialize ctr = 0
    For i = 1 to n-1:
      - i = 1: 
        numberInBtw = (stations[1] - stations[0]) / mid = 1 / 0.5 = 2
        if (stations[1] - stations[0]) == (mid * numberInBtw): numberInBtw--
        ctr += numberInBtw = 1
      - i = 2:
        numberInBtw = (stations[2] - stations[1]) / mid = 1 / 0.5 = 2
        if (stations[2] - stations[1]) == (mid * numberInBtw): numberInBtw--
        ctr += numberInBtw = 1 + 1 = 2
      - i = 3:
        numberInBtw = (stations[3] - stations[2]) / mid = 1 / 0.5 = 2
        if (stations[3] - stations[2]) == (mid * numberInBtw): numberInBtw--
        ctr += numberInBtw = 2 + 1 = 3
      - i = 4:
        numberInBtw = (stations[4] - stations[3]) / mid = 1 / 0.5 = 2
        if (stations[4] - stations[3]) == (mid * numberInBtw): numberInBtw--
        ctr += numberInBtw = 3 + 1 = 4
    Return ctr = 4
  |
  V
  Check countOfGasStations:
    if (countOfGasStations > k):
      low = mid
    else:
      high = mid
    countOfGasStations = 4, k = 4
    high = mid = 0.5
  |
  V
  Repeat until high - low <= diff:
    (This process repeats, progressively narrowing the range [low, high] until the desired precision is achieved)
  |
  V
Return high (final value of high when loop terminates)
  |
  V
Print "The smallest maximum distance is: " << high
  |
  V
End

*/
class Solution {
public:
    double findSmallestMaxDistQuadratic(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howManyPlaced(n-1, 0);
        
        for(int gasStation = 1; gasStation <= k; gasStation++){
            double maxSection = -1;
            int maxInd = -1;
            
            for(int i = 0; i < n - 1; i++){
                double diff = stations[i+1] - stations[i];
                double sectionLen = diff / (double)(howManyPlaced[i] + 1);
                if(sectionLen > maxSection){
                    maxSection = sectionLen;
                    maxInd = i;
                }
            }
            howManyPlaced[maxInd]++;
        }
        
        double maxAns = -1;
        for(int i = 0; i < n - 1; i++){
            double diff = stations[i+1] - stations[i];
            double sectionLen = diff / (double)(howManyPlaced[i] + 1);
            maxAns = max(maxAns, sectionLen);
        }
        
        return maxAns;
    }
    double findSmallestMaxDistHeapSolutionWithNlogNplusKlogN(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howManyPlaced(n-1, 0);
    
    priority_queue<pair<double,int>> pq; // Change pair<long double,int> to pair<double,int>
    
    for(int i = 0 ; i < n - 1 ; i++){
        pq.push({stations[i+1]-stations[i],i});
    }
    
    for(int gasStations = 0 ; gasStations < k ; gasStations++){ // Changed <= to <
        auto topEle = pq.top();
        pq.pop();
        int secIdx = topEle.second; // Removed () after second
        
        howManyPlaced[secIdx]++;
        
        double initialDiff = stations[secIdx + 1] - stations[secIdx]; // Change long double to double
        double newSecLen = initialDiff / (double)(howManyPlaced[secIdx] + 1); // Corrected the parenthesis
        
        pq.push({newSecLen,secIdx});
    }
    
    return pq.top().first;
}
class Solution1 {
public:
    int numberOfGasStationsRequiredUsingBinarySearch(long double distance, vector<int>& arr) {
        int n = arr.size();
        int ctr = 0;

        for (int i = 1; i < n; i++) {
            int numberInBtw = ((arr[i] - arr[i - 1]) / distance);

            if ((arr[i] - arr[i - 1]) == (distance * numberInBtw)) {
                numberInBtw--;
            }

            ctr += numberInBtw;
        }

        return ctr;
    }

    double findSmallestMaxDist(vector<int>& stations, int k) {
        int n = stations.size();
        long double low = 0;
        long double high = 0;

        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(stations[i + 1] - stations[i]));
        }

        long double diff = 1e-6;

        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int countOfGasStations = numberOfGasStationsRequiredUsingBinarySearch(mid, stations);

            if (countOfGasStations > k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};
};


