#include <bits/stdc++.h>
using namespace std;
class MySearchClass {
public:
    //Search in Quadratic time complexity and the logic is to find the largest elemet in the 2D matrix as it 
    // the largest element as well as the Peak Element.
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int maxi = INT_MIN ;
        vector<int>res(2,0);
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[i].size() ; j++){
                if(maxi < mat[i][j]){
                    maxi = mat[i][j];
                    res[0] = i ;
                    res[1] = j ;
                }
            }
        }
        return res ;
    }
    //The code is runnig in the TC : O(log(row)*col)
    int masxElementInTheRow(vector<vector<int>>& mat, int row, int col, int mid) {
        int maxi = INT_MIN;
        int index = -1;
        for (int i = 0; i < col; i++) {
            if (mat[mid][i] > maxi) {
                maxi = mat[mid][i];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGridOptimiseVersion(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> res(2, -1);
        int low = 0;
        int high = row - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxElementIndex = masxElementInTheRow(mat, row, col, mid);
            int left = mid - 1 >= 0 ? mat[mid - 1][maxElementIndex] : -1;
            int right = mid + 1 < row ? mat[mid + 1][maxElementIndex] : -1;
            if (mat[mid][maxElementIndex] > left && mat[mid][maxElementIndex] > right) {
                res[0] = mid;
                res[1] = maxElementIndex;
                return res;
            } else if (mat[mid][maxElementIndex] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
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

    vector<int> result = search.findPeakGrid(nums);

    if (result[0] != -1) {
        cout << "Target " << target << " found at position (" << result[0] << ", " << result[1] << ")." << endl;
    } else {
        cout << "Target " << target << " not found in the 2D vector." << endl;
    }

    return 0;
}