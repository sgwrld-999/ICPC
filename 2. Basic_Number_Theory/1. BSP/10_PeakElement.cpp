#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Peak element
Problem Link : https://practice.geeksforgeeks.org/problems/peak-element/1#
Solution : Binary Search
Explanation : 
    We can solve this problem using binary search. 
    We can see that if the mid element is greater than its neighbours then it is the peak element.
    If the mid element is not the peak element then we can see that if the mid element is less than the mid+1 element then the peak element will be on the right side of the mid element.
    If the mid element is less than the mid-1 element then the peak element will be on the left side of the mid element.
    We can see that the peak element will be the element which is greater than its neighbours.
    So we can use binary search to find the peak element.

    Imagine as a mountain, To reach the mountain thier will be a peak point and to reach it a slope will be thier.
    If the mid element is greater than its neighbours then it is the peak element.
    If isn't then we can say we are at the increaing slope of the mountain so we can move to the right side.
    But if the mid element is less than its neighbours then we can say we are at the decreasing slope of the mountain so we can move to the left side.
    We can use this property to find the peak element.  
    
*/


//Leetcode 162. Find Peak Element
class Solution {
public:
    int peakElementIndex(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    int low = 1, high = n-2;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {return mid;}
        else if(arr[mid] > arr[mid-1]) low = mid + 1;
        else high = mid - 1;
        }
    return -1;
    }
};

//GFG : Peak element : https://www.geeksforgeeks.org/problems/peak-element/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
int main(int argc, char const *argv[])
{
    vector<int> arr;
    int sizeOfVec ;
    cout << "Enter the size of ipVec : " ;
    cin >> sizeOfVec ;
    for (int i = 0; i < sizeOfVec ; i++)
    {
        int temp ;
        cin >> temp ;
        arr.push_back(temp);
    }
    Solution obj;
    int resultantIndex = obj.peakElementIndex(arr);
    cout << "The peak is at the " << resultantIndex << " index in the array.";
    return 0;
}

/*
Test Cases:

input :
    5
    1 2 5 4 5
*/