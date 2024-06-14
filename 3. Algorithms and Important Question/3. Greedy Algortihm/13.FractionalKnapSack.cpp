//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


/*
Problem name : Fractional Knapsack
Problem link : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
Explanation  : https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/

*/
struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/* 
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Sorting items by value-to-weight ratio in descending order
        sort(arr, arr+n, [](const auto& a, const auto& b) {
            return (double)a.value / a.weight > (double)b.value / b.weight;
        });
        
        double totalVal = 0.0; // Use double to accommodate fractional values
        
        for(int i = 0; i < n; i++) {
            if(arr[i].weight <= w) {
                totalVal += arr[i].value;
                w -= arr[i].weight;
            } else {
                totalVal += (double)(arr[i].value) / arr[i].weight * w;
                break; // Once we take a fraction of an item, we should break out of the loop
            }
        }
        
        return totalVal;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends