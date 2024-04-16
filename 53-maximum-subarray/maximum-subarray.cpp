class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms=nums[0],sum=0;
        for(auto x : nums){
            sum+=x;
            ms=max(sum,ms);
            if(sum<0)sum=0;
        }
        return ms;
    }
};