#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int iterativeBS(vector<int> ipVec,int target){
        int low = 0;
        int high = ipVec.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(ipVec[mid] == target)
                return mid;
            else if (ipVec[mid] < target)
                low = mid + 1 ;
            else 
                high = mid - 1;
        }
        return -1;
    }

    int recursiveBS(vector<int> ipVec,int low,int high,int target){
        if(low > high)
            return -1;
        int mid = low + (high - low) / 2 ;
        if(ipVec[mid] == target)
            return mid;
        else if(ipVec[mid] < target)
            return recursiveBS(ipVec,mid+1,high,target);
        else 
            return recursiveBS(ipVec,low,mid-1,target);
    }
}; 

int main(int argc, char const *argv[]) {
    int sizeOfIpVec;
    cin >> sizeOfIpVec;
    vector<int> ipVec(sizeOfIpVec);
    for (int i = 0; i < sizeOfIpVec; i++) {
        cin >> ipVec[i];
    }
    int target;
    cin >> target;
    Solution obj;
    int result = obj.recursiveBS(ipVec,0,sizeOfIpVec -1,target);
    cout << "The target element is at index: " << result << endl;
    return 0;
}