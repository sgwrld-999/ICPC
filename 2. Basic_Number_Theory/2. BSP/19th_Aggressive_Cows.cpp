/*
Problem name : Aggressive Cows
Problem link : https://practice.geeksforgeeks.org/problems/cb3e4a0f5f0b4d6a8f5d98475e9e6b6c0d6b2d0d/1
Explanation  : For the given question our task is to find an arrangemnt of the cows such that the min distance
               between the cows is maximum. What is mean by min distance between the cows is maximum is that 
               the distance between the cows should be maximum but the cows should be placed in such a way that
               the distance between the cows should be minimum.
               Let's understand with an example :
               No. of stalls = 5
               No. of cows = 3
               Stalls = 1 2 4 8 9
               Following possibliities are there :
               1 2 4 -> distance between 1 and 2 is 1, distance between 2 and 4 is 2 so the min distance is 1.
               1 2 8 -> distance between 1 and 2 is 1, distance between 2 and 8 is 6 so the min distance is 1.
               1 2 9 -> distance between 1 and 2 is 1, distance between 2 and 9 is 7 so the min distance is 1.
               1 4  8 -> distance between 1 and 4 is 3, distance between 4 and 8 is 4 so the min distance is 3.
               .
               .
               .
               .
               So on.
               But we've now a list of minimum distances between the cows. Our task is to find the maximum of 
               these minimum distances. From the above example we can see that the maximum of the minimum distances 
               is 3. So the answer is 3. 
Approach : 
Function to find the minimum distance between the cows :
1. Sort the stalls.
2. Intialize the counterVariable to 1 as the first cow is placed at the first stall.
3. Intialize the LastCowPlacedAt to the first stall as this variable will store the stall at which the last cow is placed.
4. Traverse the stalls from the second stall to the last stall.
    i. If the distance between the current stall and the LastCowPlacedAt is greater than or equal to the given distance then increment the counterVariable by 1 and update the LastCowPlacedAt to the current stall.
5. Return the (counterVariable >= cows).

For the searching the value of the minimum distance between the cows we use two methods :
1. Linear Search : 
   i. Start the search from 1 and go upto the maximum distance between the stalls.
   ii. For each value of the distance find the minimum distance between the cows.
   iii. If the minimum distance between the cows is greater than or equal to the given distance then update the answer to the current distance.
   iv. Return the answer.
2. Binary Search :
    i. Start the search from 1 and go upto the maximum distance between the stalls.
    ii. Find the mid value of the start and end.
    iii. If the minimum distance between the cows is greater than or equal to the mid value then update the answer to the mid value and update the start to mid+1.
    iv. Else update the end to mid-1.
    v. Return the answer.

*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    bool check(vector<int>& stalls, int cows, int size, int dist) {
        int lastCowPlacedAt = stalls[0];
        int ctr = 1;

        for (int i = 1; i < size; i++) {
            int difference = stalls[i] - lastCowPlacedAt;
            if (difference >= dist) {
                lastCowPlacedAt = stalls[i];
                ctr++;
            }
            if(ctr == cows) return true;
        }
        
        return false;
        
    }

    int solve(int n, int k, vector<int>& stalls) {

        // Write your code here
        sort(stalls.begin(),stalls.end());

        for (int i = 1; i < (stalls[n-1] - stalls[0]); i++) {
            if (check(stalls, k, n, i) == false) return (i-1);
        }

        return (stalls[n-1] - stalls[0]);
    }
    int solve1(int n, int k, vector<int>& stalls) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low = 0 ; 
        int high= stalls[n-1] - stalls[0] ;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(stalls,k,n,mid)) low = mid + 1;
            else high = mid - 1;
        }

        return high; //Returning high as we've to return the maximum of minimum of solution
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends