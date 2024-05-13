/*
Problem name : Find the single non-repeating element in the array where all other elements are repeating twice.
Problem link : https://leetcode.com/problems/single-element-in-a-sorted-array/
Explanation  : Given a sorted array contains pair of elements except one element. We've to find the that element.
                Brute force approach is to iterate over the array and check for the element which is not equal to its adjacent element.WHich will take O(n) time.
                But we can solve this problem in O(logn) time using binary search.
                As the array is sorted.
                So, we can use binary search to find the element. 
                How we going to trim the spaces?
                By observation we can see that 
                Before the single element -> (Even,odd) pair
                After the single element -> (Odd,Even) pair
                So, we can use this property to find the single element.
                For the end cases, we can check for the first and last element. As they can be the single element as well.
                By triming down the search space we can find the single element in O(logn) time. 
                For triming down the search space we can see that 
                if mid is even so the next element should be same as mid element 
                and if the mid is odd so the previous element should be same as mid element if this is the case then we will remove the left side as the element is on the right side.
                
*/
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int binarySearch(int arr[],int n){
        if(n == 1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        
        int low = 1 ;
        int high = n - 2;
        int mid = 0 ;
        while(low <= high){
            mid = low + (high - low) / 2 ;
            
            if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) return arr[mid];
            else if((mid%2 == 1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid+1])) low = mid + 1;
            else high = mid - 1 ;
        }
        
        return arr[mid];
    }
	int search(int A[], int N){
	    //code
	    return binarySearch(A,N);
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
