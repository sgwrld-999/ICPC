#include<bits/stdc++.h>
using namespace std;

vector<int> InsertionSortArray(vector<int>& nums) {
int n = nums.size();
for(int step = 1; step < n; step++) {
    int key = nums[step];
    int j = step - 1;

    while(j >= 0 && key < nums[j]) {
        nums[j + 1] = nums[j];
        j--;
    }
    nums[j + 1] = key;
}
return nums;
}