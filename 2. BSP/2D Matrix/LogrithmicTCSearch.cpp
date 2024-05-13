#include <bits/stdc++.h>
using namespace std;
class MySearchClass {
public:
    pair<int, int> linearPlusBinarySearch(vector<vector<int> >& nums, int target) {
        pair<int, int> ans(-1,-1);
        int rows = nums.size();
        int cols = nums[0].size();
        int low = 0 ; 
        int high = (rows * cols) - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / cols ;
            int col = mid % cols ;
            if(nums[row][col] == target){
                ans.first = row;
                ans.second = col;
                return ans;
            }
            else if(nums[row][col] < target){
                low = mid + 1;
            }else{
                high = mid - 1 ;
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
        cout << "Enter the " << i+1 << "th row elements : "  ;
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

    pair<int, int> result = search.linearPlusBinarySearch(nums, target);

    if (result.first != -1) {
        cout << "Target " << target << " found at position (" << result.first << ", " << result.second << ")." << endl;
    } else {
        cout << "Target " << target << " not found in the 2D vector." << endl;
    }

    return 0;
}
