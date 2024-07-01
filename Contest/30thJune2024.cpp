#include <vector>
#include <map>
using namespace std;

class Solution {
  public:
    long long ANDequalOR(int n, vector<int> arr) {
        long long result = 0;
        map<int, int> frequency;
        
        // Count the occurrences of each element
        for (auto it : arr) {
            frequency[it]++;
        }
        
        // Calculate the number of valid pairs for each unique element
        for (auto it : frequency) {
            long long count = it.second;
            if (count > 1) {
                result += (count * (count - 1)) / 2;
            }
        }
        
        return result;
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> arr = {816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 237, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 516, 395, 395, 395, 395, 395, 395, 395, 395, 395, 395, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 816, 231, 231, 231, 231, 757};
    int n = 191;
    long long result = sol.ANDequalOR(n, arr);
    printf("%lld\n", result); // should output the correct number of pairs
    return 0;
}
