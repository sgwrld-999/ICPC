
/*
Problem : Find the floor and ceil of a number in a sorted array
Problem Link : https://www.geeksforgeeks.org/floor-in-a-sorted-array/
Explanation : Floor : smallest element in the array which is greater than or equal to the target element or {Element <= target}
Ceil : smallest element in the array which is greater than or equal to the target element or {Element >= target}
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        int l = 0 ;
        int h = n - 1 ;
        int ans = -1 ;
        while(l <= h){
            int mid = l + (h - l) / 2 ;
            if(v[mid] == x) return mid;
            else if(v[mid] < x){
                ans = mid;
                l = mid + 1 ; // update l to search in the right half
            }else{
                h = mid - 1 ; // update h to search in the left half
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends