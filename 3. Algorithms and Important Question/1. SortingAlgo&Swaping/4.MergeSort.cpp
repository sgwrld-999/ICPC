#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to merge two sorted subarrays into a single sorted subarray
    void merge(vector<int>& nums, int low, int mid, int high) {
        int n1 = mid - low + 1; // Size of the left subarray
        int n2 = high - mid; // Size of the right subarray
        vector<int> left(n1), right(n2); // Create temporary arrays to store the left and right subarrays
        
        // Copy elements from the original array to the left subarray
        for(int i = 0; i < n1; i++) {
            left[i] = nums[low + i];
        }
        
        // Copy elements from the original array to the right subarray
        for(int i = 0; i < n2; i++) {
            right[i] = nums[mid + 1 + i];
        }
        
        int i = 0, j = 0, k = low; // Initialize indices for merging
        
        // Merge the left and right subarrays into the original array in sorted order
        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
        
        // Copy the remaining elements from the left subarray, if any
        while(i < n1) {
            nums[k] = left[i];
            i++;
            k++;
        }
        
        // Copy the remaining elements from the right subarray, if any
        while(j < n2) {
            nums[k] = right[j];
            j++;
            k++;
        }
    }
    
    // Function to perform merge sort on the given array
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int mid = low + (high - low) / 2; // Calculate the middle index
            
            // Recursively divide the array into two halves and merge them
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }
};

int main() {
    Solution obj;
    vector<int> nums = {9,1,5,6,2,3}; // Input array
    
    obj.mergeSort(nums, 0, nums.size() - 1); // Perform merge sort on the array
    
    // Print the sorted array
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    
    return 0;
}
