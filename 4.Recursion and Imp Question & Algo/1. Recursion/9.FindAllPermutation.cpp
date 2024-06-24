#include<bits/stdc++.h>
using namespace std;

/*
Problem name : Find all Permutations of a string which has Unique Characters or integers

Explanation : As question is saying find all permutations of a string which has unique characters. Which is a clear indication of the 
              recursion and backtracking. So, we will use the recursion and backtracking to solve this problem. We will use the
                recursion to find all the permutations of the string and we will use the backtracking to remove the character from the
                string which we have already used in the permutation. So, we will use the map to keep track of the characters which we
                have already used in the permutation. So, we will use the map to keep track of the characters which we have already used
                and we will use the recursion to find all the permutations of the string.

                
*/
class Solution {
public:
    void recursion(const string &S, vector<string> &ans, vector<char> &storeVec, map<char, bool> &mp, int sizeOfString) {
        if (storeVec.size() == sizeOfString) {
            string result(storeVec.begin(), storeVec.end());
            ans.push_back(result);
            return;
        }

        for (int i = 0; i < sizeOfString; i++) {
            if (!mp[S[i]]) {
                storeVec.push_back(S[i]);
                mp[S[i]] = true;
                recursion(S, ans, storeVec, mp, sizeOfString);
                mp[S[i]] = false;
                storeVec.pop_back();
            }
        }
    }

    vector<string> find_permutation(string S) {
        map<char, bool> mp;
        for (char it : S) {
            mp[it] = false;
        }

        vector<string> ans;
        vector<char> storeVec;

        recursion(S, ans, storeVec, mp, S.length());
        return ans;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(),ans.end());
        for(auto i: ans)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
