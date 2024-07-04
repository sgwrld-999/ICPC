#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long base = 31;

vector<long long> precompute_powers(int n) {
    vector<long long> p(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * base) % mod;
    }
    return p;
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    if (n == 0 || m == 0) {
        cout << "Empty string, no hash to compute." << endl;
        return 0;
    }
    vector<long long> p = precompute_powers(max(n, m));
    vector<long long> hashOfS(n + 1, 0);
    for(int i = 0; i < n; i++) {
        hashOfS[i + 1] = (hashOfS[i] + (s[i] - 'a' + 1) * p[i]) % mod;
    }
    long long hashOfT = 0;
    for (int i = 0; i < m; i++) {
        hashOfT = (hashOfT + (t[i] - 'a' + 1) * p[i]) % mod;
    }

    vector<int> occurrences;
    for(int i = 0; i + m <= n; i++) {
        long long currentHash = (hashOfS[i + m] - hashOfS[i] + mod) % mod;
        if(currentHash == hashOfT * p[i] % mod) {
            occurrences.push_back(i);
        }
    }

    for (int pos : occurrences) {
        cout << "Pattern found at position: " << pos << endl;
    }

    return 0;
}
