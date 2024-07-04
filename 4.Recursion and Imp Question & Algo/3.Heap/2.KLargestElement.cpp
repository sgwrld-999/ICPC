#include<bits/stdc++.h>
using namespace std;
/*
Problem name : K largest elements
Problem Link : https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1
Sample input : 6 3 7 10 4 3 20 15
*/
class Solution {
    public:
    vector<int> kLargestElement(vector<int>inputVector,int k, int n){
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            minHeap.push(inputVector[i]);
            if(minHeap.size() > k){
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

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> inputVector(n);
    for(int i = 0; i < n; i++){
        cin >> inputVector[i];
    }
    Solution obj;
    vector<int> ans = obj.kLargestElement(inputVector, k, n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}