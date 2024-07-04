#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long base = 31; // Assuming the dataset has only lowercase letters

// Precomputing the powers of base to avoid overflow
long long compute_hash(string const &s) {
    long long hash_value = 0;
    long long p = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p) % mod;
        p = (p * base) % mod;
    }
    return hash_value;
}


int main() {
    vector<string> s = {
        "abacaba",
        "abacabadabacaba",
        "abacabadabacabae",
        "abacabadabacabaf",
        "abacabadabacabag",
        "abacabadabacabah",
        "abacabadabacabai",
        "abacabadabacabaj",
        "abacabadabacabak",
        "abacabadabacabal",
        "abacabadabacabam"
    };
    
    for (auto &i : s) {
        cout << compute_hash(i) << endl;
    }
    return 0;
}
