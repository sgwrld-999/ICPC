#include<bits/stdc++.h>
using namespace std;
/*
Problem name : Kth smallest element
Problem Link : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
Sample input : 6 3 7 10 4 3 20 15
Sample Output : 7
Explanation: 
How to identify the problem is of heap?
1. We have given k.
2. We have to find the smallest/Largest element.
3. Sorting is allowed.
*/
class Solution {
    public:
    int kthSmallestElement(vector<int>inputVector,int k, int n){
        priority_queue<int> maxHeap;
        for(int i = 0; i < n; i++){
            maxHeap.push(inputVector[i]);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> inputVector(n);
    for(int i = 0; i < n; i++){
        cin >> inputVector[i];
    }
    Solution obj;
    cout << obj.kthSmallestElement(inputVector, k, n) << endl;
    return 0;
}

