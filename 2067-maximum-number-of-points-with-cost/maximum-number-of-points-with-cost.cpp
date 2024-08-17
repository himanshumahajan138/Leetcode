class Solution {
public:
    static long long maxPoints(vector<vector<int>>& points) {
        const int r=points.size(), c=points[0].size();
        vector<vector<long long>> dp(2, vector<long long>(c, 0));

        // Initialize 0th row
        for (int j=0; j<c; j++)
            dp[0][j]=points[0][j];

        // DP Calculation
        for (int i=1; i < r; i++) {
            vector<long long> left(c, 0), right(c, 0);

             // Compute max from right downto col j=c-1...0
            right[c-1]=dp[(i-1)&1][c-1];
            for (int j=c-2; j >= 0; j--)
                right[j] = max(right[j+1]-1, dp[(i-1)&1][j]);

            // Compute max from left to col j=0...c-1
            left[0]=dp[(i-1)&1][0];
            dp[i&1][0]=max(left[0], right[0])+points[i][0];
            for (int j=1; j < c; j++){
                left[j]=max(left[j-1]-1, dp[(i-1)&1][j]);
                dp[i&1][j] = max(left[j], right[j])+points[i][j];// update DP
            }
        }

        // Find the maximum value
        return *max_element(dp[(r-1)&1].begin(), dp[(r-1)&1].end());
    }
};



auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

