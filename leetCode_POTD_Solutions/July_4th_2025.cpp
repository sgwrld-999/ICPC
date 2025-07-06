#include<iostrem>
#include<vector>

class Solution {
public:
    /**
     * Thought process:
     * 1. ATQ: Find the k-th character in an evolving string S.
     * 2. We start with S = "a".
     * 3. Each operation op extends S to S + T, where:
     *      - if op == 0: T = S
     *      - if op == 1: T = shift-each-char(S) (with 'z'→'a').
     * 4. Directly building S is infeasible for large k, so we track only lengths:
     *      len[0] = 1, len[i] = len[i-1] * 2, until len >= k.
     * 5. To locate the k-th character, walk the operations backwards:
     *      - Let half = len[i-1].
     *      - If k > half, then k -= half, and if op[i-1] == 1, record one shift.
     * 6. Finally, starting from 'a' (base string), apply total shifts mod 26.
     *
     * @param k 1-based index into the evolving string.
     * @param operations Vector of operations (0: copy, 1: copy+shift).
     * @return The k-th character, between 'a' and 'z'.
     */
    char kthCharacter(long long k, const vector<int>& operations) {
        // 1) Build prefix lengths until we exceed k
        vector<long long> prefixLen;
        prefixLen.reserve(operations.size() + 1);
        prefixLen.push_back(1);  // initial string length

        for (int op : operations) {
            long long nextLen = prefixLen.back() * 2;
            prefixLen.push_back(nextLen);
            if (nextLen >= k) break;
        }

        // 2) Walk backwards to map k back to the base string,
        //    tracking how many total shifts we need.
        int totalShifts = 0;
        int levels = prefixLen.size() - 1; // number of operations actually used
        for (int i = levels; i >= 1; --i) {
            long long half = prefixLen[i - 1];
            if (k > half) {
                k -= half;
                if (operations[i - 1] == 1) {
                    totalShifts = (totalShifts + 1) % 26;
                }
            }
        }

        // 3) Base character index (0 for 'a'), then apply shifts.
        int baseIndex = static_cast<int>((k - 1) % 26);
        return char('a' + (baseIndex + totalShifts) % 26);
    }
};

