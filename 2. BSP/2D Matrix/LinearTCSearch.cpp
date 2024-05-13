#include <bits/stdc++.h>
using namespace std;

class MySearchClass {
public:
    pair<int, int> linearTCSearch(vector<vector<int> >& nums, int target) {
        pair<int, int> ans(-1, -1);
        int rowsSize = nums.size();
        int colSize = nums[0].size();
        int row = 0 ; 
        int col = colSize - 1 ;
        while (row < rowsSize && col >= 0)
        {
            if(nums[row][col] == target){
                ans.first = row;
                ans.second = col;
                return ans;
            }
            else if(nums[row][col] < target){
                row++;
            }
            // else if(nums[row][col] > target){
            //     col--;
            // } // both works correctly
            else{
                col--;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    MySearchClass search;

    vector<vector<int> > nums;
    int row , col ;
    cout << "Enter the row and col : " ;
    cin >> row >> col ;
    for (int i = 0; i < row ; i++)
    {
        cout << "Enter the " << i << "th row elements"  ;
        vector<int> temp(col);
        for (int j = 0; j < col ; j++)
        {
            cin >> temp[j];
        }
        nums.push_back(temp);
    }
    int target ;
    cout << "Enter the target :" ;
    cin >> target ;
    pair<int, int> result = search.linearTCSearch(nums, target);

    if (result.first != -1) {
        cout << "Target " << target << " found at position (" << result.first << ", " << result.second << ")." << endl;
    } else {
        cout << "Target " << target << " not found in the 2D vector." << endl;
    }

    return 0;
}

