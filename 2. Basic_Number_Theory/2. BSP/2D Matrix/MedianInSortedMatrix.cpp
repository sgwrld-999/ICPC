#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //The Brute Force method 
    // TC : O(R*C)
    //Space Complecity : O(R+C)
    int median(vector<vector<int>> &matrix, int R, int C){
        int sizeOf1D = R * C ;
        vector<int> arr ;
        for(int i = 0 ; i < R ; i++){
            for(int j = 0 ; j < C ; j++){
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int medianIndex = 0 + (sizeOf1D - 0) / 2 ;
        return arr[medianIndex];
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}