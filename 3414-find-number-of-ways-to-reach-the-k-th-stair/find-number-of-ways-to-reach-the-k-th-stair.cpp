const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    unordered_map<int, vector<vector<int>>> dp;
    
    int find(int k, int i, int jump, bool possible) {
        if (i > k + 5 || jump > 31)
            return 0;
        

        if(dp.count(i) && dp[i][jump][possible] != -1) return dp[i][jump][possible];

        int ans = (i == k);
        
        if (possible)ans += find(k, i - 1, jump, 0);
        
        if (i + (1 << jump) <= k + 1)ans += find(k, i + (1 << jump), jump + 1, 1);

        dp[i].resize(32, vector<int>(2, -1));

        return dp[i][jump][possible] = ans;
    }
    
    int waysToReachStair(int k) {
        return find(k,1,0,1);
    }
};