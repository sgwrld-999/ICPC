#include<bits/stdc++.h>
using namespace std;
/*
The given code snippet is very important is question of subsequences
as in this we have to either take it or not take it and then we have to
print the subsequences.
Flow of code : 
1. Base case : If the index is greater than the size of the array then we have to print the vector
2. Recursive case : 
    a. Add the element to the vector and call the function again
    b. Remove the element from the vector and call the function again
*/
class Solution{
public:
    void printAllSubsequence(vector<int> arr,int idx,vector<int>& ans){
        if(idx >= arr.size()){
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
            return ;
        }

        ans.push_back(arr[idx]); //take the element 
        printAllSubsequence(arr, idx + 1, ans); // increment idx here
        ans.pop_back(); //don't take the element
        printAllSubsequence(arr, idx + 1, ans); // increment idx here as well
    }
};


int main(){
    Solution s;
    vector<int> arr = {1,2,3};
    vector<int> ans;
    s.printAllSubsequence(arr,0,ans);
    return 0;
}
