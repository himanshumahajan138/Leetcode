class Solution {
public:
    vector<int> dp; 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        dp.assign(n, -1);
        function<int(int)> f=[&](int i) mutable
        {
            if (i>=n) return 0;
            if (dp[i]!=-1) return dp[i];
            int ans=INT_MAX;
            int j=i;
            int d=days[i];
            
            while(j<n && days[j]<d+1) j++;
            ans=min(ans, f(j)+costs[0]);
            while( j<n && days[j]<d+7) j++;
            ans=min(ans, f(j)+costs[1]);
            while( j<n && days[j]<d+30) j++;
            ans=min(ans, f(j)+costs[2]);            
            return dp[i]=ans;   
        };
        return f(0); 
    }
};