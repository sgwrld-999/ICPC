#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const long long base = 31; // Assuming the dataset has only lowercase letters

vector<long long> precompute_powers(int n) {
    vector<long long> p(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * base) % mod;
    }
    return p;
}

vector<long long> precompute_hashes(const string &s, const vector<long long> &p) {
    int n = s.size();
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) *                                                                                                                                                                                                                            p[i]) % mod;
    }
    return h;
}

long long hashOfSubStr(int l, int r, const vector<long long> &p, const vector<long long> &h) {
    return (h[r] - (h[l] * p[r - l]) % mod + mod) % mod;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 0) {
        cout << "Empty string, no hash to compute." << endl;
        return 0;
    }

    vector<long long> p = precompute_powers(n);
    vector<long long> h = precompute_hashes(s, p);

    int i, j;
    cout << "Enter the indices i and j for which you want to compute the hash: ";
    cin >> i >> j;

    if (i < 0 || j >= n || i > j) {
        cout << "Invalid indices." << endl;
        return 1;
    }

    long long hashValue = hashOfSubStr(i, j + 1, p, h);
    cout << "Hash value of the substring from index " << i << " to " << j << " is: " << hashValue << endl;

    return 0;
}
