#include <bits/stdc++.h>
using namespace std;

class MySearchClass {
public:
    pair<int, int> linearSearch(vector<vector<int> >& nums, int target) {
        pair<int, int> ans(-1, -1);
        int rows = nums.size();
        for (int i = 0; i < rows; i++) {
            int colSize = nums[i].size();
            for (int j = 0; j < colSize; j++) {
                if (nums[i][j] == target) {
                    ans.first = i;
                    ans.second = j;
                    return ans;
                }
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

    pair<int, int> result = search.linearSearch(nums, target);

    if (result.first != -1) {
        cout << "Target " << target << " found at position (" << result.first << ", " << result.second << ")." << endl;
    } else {
        cout << "Target " << target << " not found in the 2D vector." << endl;
    }

    return 0;
}

