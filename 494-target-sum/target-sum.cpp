class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int n = nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        int diff=sum-target;

        // Check if it's possible to achieve the target
        if (diff<0|| diff%2!=0) return 0;

        diff/=2;

        vector<int> dp(diff+1, 0);
        dp[0] = 1;

        for (int x: nums) {
            for (int sum=diff; sum>=x; sum--) 
                dp[sum]+=dp[sum-x]; 
            
        }
        return dp[diff];
    }
};