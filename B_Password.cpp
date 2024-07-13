#include <iostream>
#include <string>
using namespace std;

long long mod = 1e9 + 7;
long long base = 31;

class Solution {
public:
    vector<long long> precomputed_powers(int n) {
        vector<long long> precomputedPower(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            precomputedPower[i] = (precomputedPower[i - 1] * base) % mod;
        }
        return precomputedPower;
    }

    vector<long long> precomputed_hashFunction(const string& s, const vector<long long>& precomputed_power) {
        int n = s.length();
        vector<long long> precomputed_hash(n + 1, 0);

        for (int i = 0; i < n; i++) {
            precomputed_hash[i + 1] = (precomputed_hash[i] + (s[i] - 'a' + 1) * precomputed_power[i]) % mod;
        }
        return precomputed_hash;
    }

    long long hashOfSubStr(int l, int r, const vector<long long>& precomputed_power, const vector<long long>& precomputed_hash) {
        return (precomputed_hash[r + 1] - (precomputed_hash[l] * precomputed_power[r - l + 1]) % mod + mod) % mod;
    }

    string password(const string& s) {
        int n = s.length();
        vector<long long> precomputed_power = precomputed_powers(n);
        vector<long long> precomputed_hash = precomputed_hashFunction(s, precomputed_power);

        for (int len = n / 2; len > 0; len--) {
            long long prefix_hash = hashOfSubStr(0, len - 1, precomputed_power, precomputed_hash);
            long long suffix_hash = hashOfSubStr(n - len, n - 1, precomputed_power, precomputed_hash);

            if (prefix_hash == suffix_hash) {
                for (int i = 1; i <= n - len - 1; i++) {
                    if (hashOfSubStr(i, i + len - 1, precomputed_power, precomputed_hash) == prefix_hash) {
                        return s.substr(0, len);
                    }
                }
            }
        }
        return "Just a legend";
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.password(s) << '\n';
    return 0;
}
