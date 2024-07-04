//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*
Problem name: Nearly Sorted Algorithm
Problem Link: https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0
Explanation: 
According to Nearly Sorted Algorithm, an array is said to be nearly sorted if each element is misplaced by no more than k positions from the correct sorted position. The task is to sort the array.
Let's understand with the help of an example:
Input: arr[] = {6, 5, 3, 2, 8, 10, 9}
k = 3
Output: 2 3 5 6 8 9 10

Here k define that for any position the correct element can be at most k distance away.
For 0th index the correct element for that particular index can be at 1st, 2nd or 3rd index.
For 1st index the correct element for that particular index can be at 0th, 1st, 2nd, 3rd or 4th index.
For 2nd index the correct element for that particular index can be at 0th, 1st, 2nd, 3rd, 4th or 5th index, 3 index backwards or 3 index forward.
So, the output will be 2 3 5 6 8 9 10

*/
// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        priority_queue<int,vector<int>,greater<int>> minHeap;
        vector <int> ans;
        
        for(int i =  0 ; i < num ; i++){
            minHeap.push(arr[i]);
            if(minHeap.size() > k){
                ans.push_back(minHeap.top());
                minHeap.pop();
            }
        }
        
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
                minHeap.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends