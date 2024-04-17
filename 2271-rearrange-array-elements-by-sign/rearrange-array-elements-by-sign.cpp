class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n=nums.size(),pi=0,ni=1;
        vector<int>ans(n,0);
        for(auto ele:nums){
            if(ele>=0){
                ans[pi]=ele;
                pi+=2;
            }
            else{
                ans[ni]=ele;
                ni+=2;
            }
        }
        return ans;
    }
};