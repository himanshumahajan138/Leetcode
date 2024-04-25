const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int longestIdealString(string s, int k)
    {
        int dp[26] = {};

        for(char c : s)
        {
            int mx = 0,
                ch = c - 'a';

            for(int i = max(0, ch - k); i <= min(25, ch + k); ++i) mx = max(mx, dp[i]);
            dp[ch] = 1 + mx;
        }

        return *max_element(begin(dp), end(dp));
    }
};