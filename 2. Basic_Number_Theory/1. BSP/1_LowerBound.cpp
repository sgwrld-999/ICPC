#include <bits/stdc++.h>
using namespace std;
/*
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index as ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
*/
class MySolution {
public:
    int lowerBound(vector<int>& ipVec, int low, int high, int target) {
        int ans = -1;
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            if (ipVec[mid] >= target) {
                ans = mid ;
                high = mid - 1 ;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    MySolution solution;
    int target;
    cin >> target;
    int result = solution.lowerBound(ipVec, 0, sizeOfIpVec - 1, target);
    cout << "Lower Bound : " << result << endl;
    return 0;
}
