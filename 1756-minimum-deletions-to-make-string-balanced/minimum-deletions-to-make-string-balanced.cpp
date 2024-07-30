class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int ans = 0;
        int count_b = 0;
        // dp(i) gives the number of characters to be deleted to make substring
        // s(0,i) valid corresponingly ans variable represents dp[i]
        for (int i = 0; i < n; i++) {
            // it is always valid to append b at the
            if (s[i] == 'b')
                count_b++;
            else {
                // two cases arise
                // case1: we remove a
                // case2: keep a, then count_b number of characters will need to
                // be removed
                ans = min(ans + 1, count_b);
            }
        }
        return ans;
    }
};