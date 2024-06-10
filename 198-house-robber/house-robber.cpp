class Solution {
public:

    int solve(vector<int>&dp,vector<int>&arr,int i){
        if(i<0)return 0;
        if(i==0)return arr[i];
        if(dp[i]!=-1)return dp[i];
        int take = arr[i]+solve(dp,arr,i-2);
        int nottake= solve(dp,arr,i-1);
        return dp[i]= max(take,nottake);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        
        return solve(dp,nums,nums.size()-1);
    }
};