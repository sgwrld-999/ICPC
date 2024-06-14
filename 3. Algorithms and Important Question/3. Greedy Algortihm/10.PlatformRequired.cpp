//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

/*
Problem name : Minimum Platforms
Problem link : https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
Problem Statement : Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.
Explanation: 
Brute approach:
Find the maximum number of trains that are on the platform at the same time.
Itertate over the arrival and departure times of the trains.
Take a count variable and initialize it with 0.
Take a maxCount variable and initialize it with 0.
Iterate over the arrival and departure times of the trains.
    For each arrival time of the train:
        Increment the count.
        For each departure time of the train:
            Decrement the count.
        Update the maxCount with the maximum of maxCount and count.
Return maxCount.


Optimized approach:
Sort the arrival and departure times.
Take two pointers i and j and initialize them with 0.
Take a count variable and initialize it with 0.
Take a maxCount variable and initialize it with 0.
While i is less than n and j is less than n:
    If the arrival time of the train is less than or equal to the departure time of the train:
        Increment the count and increment i.
    Else:
        Decrement the count and increment j.
    Update the maxCount with the maximum of maxCount and count.
Return maxCount.

We are still finding the maximum number of trains that are on the platform at the same time but in an optimized way.
*/
// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i = 0 ; 
    	int j = 0 ;
    	int count = 0 ;
    	int maxCount = 0 ;
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    
    	    maxCount = max(maxCount,count);
    	}
    	
    	return maxCount ;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends