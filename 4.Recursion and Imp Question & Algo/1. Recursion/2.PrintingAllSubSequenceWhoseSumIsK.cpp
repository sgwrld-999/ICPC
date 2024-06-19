#include<bits/stdc++.h>
using namespace std ;

class Solution{
    public: 
    vector<vector<int>> printAllSubSequenceWhoseSumIsK(vector<vector<int>> &ans,vector<int> arr,vector<int> &temp,int idx,int k,int sum,int sizeOfArr){
        if(idx >= sizeOfArr){
            if(sum == k){
                ans.push_back(temp);
            }
            return ans;
        }
    
        temp.push_back(arr[idx]);//take the element and call the function again
        printAllSubSequenceWhoseSumIsK(ans,arr,temp,idx+1,k,sum+arr[idx],sizeOfArr);
        temp.pop_back();//don't take the element and call the function again
        printAllSubSequenceWhoseSumIsK(ans,arr,temp,idx+1,k,sum,sizeOfArr);
        
        return ans; // Add this return statement
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3,4,5};
    vector<int> temp;
    vector<vector<int>> ans;
    int k = 10;
    int sizeOfArr = arr.size();
    s.printAllSubSequenceWhoseSumIsK(ans,arr,temp,0,k,0,sizeOfArr);
    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}