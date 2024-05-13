#include<bits/stdc++.h>
using namespace std;
// Problem name : Peak element in Mountain Array
// Problem Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Explanatino : Same as peak element but the array is a mountain array. Which means the array is increasing and then decreasing.
// So only one peak element will be there in the array.
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int h = n - 1;
        
        while (h >= l) {
            int mid = l + (h - l) / 2;
            if (arr[mid] > arr[mid + 1]) {
                h = mid - 1;
            }
            else if (arr[mid] < arr[mid + 1]) {
                l = mid + 1;
            }
        }
        return l;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> arr;
    int sizeOfVec ;
    cout << "Enter the size of ipVec : " ;
    cin >> sizeOfVec ;
    for (int i = 0; i < sizeOfVec ; i++)
    {
        int temp ;
        arr.push_back(temp);
    }
    Solution obj;
    int resultantIndex = obj.peakIndexInMountainArray(arr);
    cout << "The peak is at the " << resultantIndex << " index in the array.";
    return 0;
}
