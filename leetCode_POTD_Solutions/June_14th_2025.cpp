#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);

        string maxStr = str;
        string minStr = str;

        // Replace first non-9 digit in maxStr with '9'
        char toReplaceMax = '\0';
        for (char ch : str) {
            if (ch != '9') {
                toReplaceMax = ch;
                break;
            }
        }

        if (toReplaceMax != '\0') {
            for (char &ch : maxStr) {
                if (ch == toReplaceMax) ch = '9';
            }
        }

        // Replace first digit (not '1') in minStr with '0'
        char toReplaceMin = str[0];
        for (char &ch : minStr) {
            if (ch == toReplaceMin) ch = '0';
        }

        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);

        return maxNum - minNum;
    }
};


int main(){
	int num1;
	cin >> num1;
	Solution sol;
	int res = sol.minMaxDifference(num1);
}
