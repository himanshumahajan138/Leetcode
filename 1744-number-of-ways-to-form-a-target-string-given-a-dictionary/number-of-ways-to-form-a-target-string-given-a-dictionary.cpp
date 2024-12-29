class Solution {
public:
    static int numWays(vector<string>& words, string& target) {
        const int mod=1e9+7;
        const int m=target.size(), n=words[0].size();
        
        // count freq
        int freq[26][1000]={0};
        for (int i = 0; i<n; i++) {
            for (const auto& w : words) 
                freq[w[i]-'a'][i]++;
        }
        
        //1D DP array for optimization
        int dp[1001]={0};
        dp[0]=1; // Base case
        
        for (int i=0; i<n; i++) {
            // Traverse target from back to front to avoid overwriting
            for (int j=m; j>=1; j--) {
                long long fc=freq[target[j-1]-'a'][i];// avoid of overflowing
                dp[j]=(dp[j]+dp[j-1]*fc) % mod;    
            }
        }
        return dp[m];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();