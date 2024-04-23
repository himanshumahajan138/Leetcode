class Solution {
public:
    int minimumOperations(vector<vector<int>>& candy) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        const int m = candy.size(), n = candy[0].size();
        assert(m >= 1 && m <= 1000);
        assert(n >= 1 && n <= 1000);
        vector<int> dp(10);
        for (int j = 0; j < n; ++j) {
            vector<int> v(10);
            for (int i = 0; i < m; ++i) {
                assert(candy[i].size() == n);
                ++v[candy[i][j]];
                assert(candy[i][j] >= 0 && candy[i][j] <= 9);
            }
            vector<int> temp(10, INT_MAX);
            for (int i = 0; i < 10; ++i) {
                int t = INT_MAX;
                for (int j = 0; j < 10; ++j) {
                    if (j != i) {
                        t = min(t, dp[j]);
                    }
                }
                temp[i] = min(temp[i], t + m - v[i]);
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};