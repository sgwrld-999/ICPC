#include<bits/stdc++.h>
using namespace std;

// Function to partition the array
// It selects a pivot element and places it at its correct position in the sorted array
int partition(int arr[], int l, int h) {
    int pivot = arr[l]; // Selecting the first element as the pivot
    int i = l, j = h;

    while (i < j) {
        // Move the left pointer until we find an element greater than the pivot
        do {
            i++;
        } while (arr[i] <= pivot);

        // Move the right pointer until we find an element smaller than or equal to the pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // Swap the elements at i and j if i < j
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place the pivot element at its correct position
    swap(arr[l], arr[j]);

    // Return the index of the pivot element
    return j;
}

// Function to perform quicksort
void quickSort(int arr[], int l, int h) {
    if (l < h) {
        // Partition the array and get the index of the pivot element
        int j = partition(arr, l, h);

        // Recursively call quicksort on the left and right subarrays
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}