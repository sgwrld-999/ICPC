#include<bits/stdc++.h>
using namespace std;

// Function to perform counting sort on the given array
void countingSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = *max_element(arr, arr + n);

    // Create a count array to store the count of each element
    vector<int> count(max + 1, 0);

    // Store the count of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Update the count array to store the cumulative count of elements
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted output
    int output[n];

    // Traverse the input array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        // Place the element at its correct position in the output array
        output[count[arr[i]] - 1] = arr[i];

        // Decrement the count of the element
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countingSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}