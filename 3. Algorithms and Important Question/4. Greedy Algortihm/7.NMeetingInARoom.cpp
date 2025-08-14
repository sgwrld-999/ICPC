//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
Problem name : N meetings in one room
Problem link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
Explanation: https://takeuforward.org/data-structure/n-meetings-in-one-room/
*/
struct meeting {
    int start;
    int end;
    int pos;
};

class Solution {
public:
    // Comparison function to sort meetings by end time
    static bool comparison(const meeting& A, const meeting& B) {
        return A.end < B.end;
    }

    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i;
        }

        // Sorting meetings by end time
        sort(meet, meet + n, comparison);

        int ans = 1; // Start with the first meeting
        int limit = meet[0].end;

        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                ans++;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends