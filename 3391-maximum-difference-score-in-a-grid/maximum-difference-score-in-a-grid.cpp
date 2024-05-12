const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> max_val(m,vector<int>(n, -1e9));
        
        max_val[m-1][n-1] = grid[m-1][n-1];
        
        int i=m-1;
        int j;
        while(i>=0){
            j=n-1;
            
            while(j>=0){
                if (i < m-1) {
                    max_val[i][j] = max(max_val[i][j], max_val[i+1][j]);
                }
                if (j < n-1) {
                    max_val[i][j] = max(max_val[i][j], max_val[i][j+1]);
                }
                max_val[i][j] = max(max_val[i][j], grid[i][j]);
                --j;
            }
            --i;
        }

        int maxi = -1e9;
        i=0;
        while(i<m){
            j=0;
            while(j<n){
                if (i < m-1)maxi = max(maxi, max_val[i+1][j] - grid[i][j]);
                if (j < n-1) {
                    maxi = max(maxi, max_val[i][j+1] - grid[i][j]);
                }
                ++j;
            }
            ++i;
        }

        return maxi;
    }
};