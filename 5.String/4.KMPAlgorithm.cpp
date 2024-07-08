#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0; // Length of the previous longest prefix suffix
    int m = pattern.length();
    lps[0] = 0; // LPS[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm for pattern searching
vector<int> KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m);
    vector<int> result;

    // Preprocess the pattern (calculate LPS array)
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

int main() {
    string text = "ababcababcabc";
    string pattern = "abc";
    vector<int> result = KMPSearch(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : result) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
