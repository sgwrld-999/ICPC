#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char &ch : s) freq[ch]++;

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        // Loop over frequency map entries
        for (auto &entry : freq) {
            int count = entry.second;

            // If count is even
            if (count % 2 == 0) {
                minEven = min(minEven, count);
            }
            // If count is odd
            else {
                maxOdd = max(maxOdd, count);
            }
        }

        // If no even or no odd found, return -1 (or any appropriate value)
        if (maxOdd == INT_MIN || minEven == INT_MAX) return -1;

        return maxOdd - minEven;
    }
};


int main(){
	string str1;
	cin >> str1;
	Solution sol;
	int res = sol.maxDifference(str1);
	cout << res << endl;
	return 0;	
}	
