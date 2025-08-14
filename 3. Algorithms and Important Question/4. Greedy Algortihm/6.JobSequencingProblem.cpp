//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int deadline; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int deadline; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class Solution {
public:
    static bool comparison(Job A, Job B) {
        return (A.profit > B.profit);
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparison);

        int maxDL = 0;
        for (int i = 0; i < n; i++) {
            maxDL = max(maxDL, arr[i].deadline);
        }

        vector<int> slots(maxDL + 1, -1); 

        int ctrJobs = 0;
        int jobProf = 0;
        for (int i = 0; i < n; i++) {
            
            for (int j = arr[i].deadline; j > 0; j--) {
                if (slots[j] == -1) {
                    slots[j] = i;  
                    ctrJobs++;
                    jobProf += arr[i].profit;
                    break;
                }
            }
        }
        return vector<int>{ctrJobs, jobProf};
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].deadline = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0; 
}



// } Driver Code Ends