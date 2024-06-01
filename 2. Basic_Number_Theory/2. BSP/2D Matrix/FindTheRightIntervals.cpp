#include<bits/stdc++.h>
using namespace std;

class MySearchClass {
public:
    vector<int> findRightInterval(vector<vector<int>>& arr) {
        int row = arr.size();
        vector<int> res(row, -1);
        if (row == 1 && arr[0][0] == arr[0][1]) {
            res[0] = 0 ;
            return res;
        }
        if(row == 1 ){
            return res;
        }
        vector<pair<int, int>> itv;
        for (int i = 0; i < row; i++) {
            itv.push_back({arr[i][0], i});
        }
        sort(itv.begin(), itv.end());
        for(int i = 0 ; i < row ; i++){
            int temp = arr[i][1];
            for(int j = 0 ; j < row ; j++){
                if(temp <= itv[j].first && i != j){
                    res[i] = itv[j].second ;
                    continue;
                }
            }
        }
        return res;
    }
    vector<int> findRightIntervalOptimalSolution(vector<vector<int>>& arr) {
        int row = arr.size();
        vector<int> res(row, -1);
        if (row == 1 && arr[0][0] == arr[0][1]) {
            res[0] = 0 ;
            return res;
        }
        if(row == 1 ){
            return res;
        }
        vector<pair<int, int>> itv;
        for (int i = 0; i < row; i++) {
            itv.push_back({arr[i][0], i});
        }
        sort(itv.begin(), itv.end());
        for (int i = 0; i < row; i++) {
            int end = arr[i][1];
            int low = 0;
            int high = row - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (end <= itv[mid].first) {
                    res[i] = itv[mid].second;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
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
    vector<int> result = search.findRightInterval(nums);
    return 0;
}