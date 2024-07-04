#include<bits/stdc++.h>
using namespace std;
/*
Problem 1 : Find K Closest Elements
Link : https://leetcode.com/problems/find-k-closest-elements/
Solution : 
Approach 1 : Using so
Approach 2 : Using heap
*/
class Solution1 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>> pairVec;
        for(auto it : arr){
            pairVec.push_back({abs(it-x), it});
        }

        sort(pairVec.begin(), pairVec.end());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pairVec[i].second);
        }

        sort(ans.begin(), ans.end()); 
        return ans;
    }
};
class Solution2{
    public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxHeap;
        for(auto it : arr){
            maxHeap.push({abs(it-x), it});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<int> ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};