const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        for(int num=0;num<(1<<n);++num){
            temp={};
            for(int i=0;i<n;++i){
                if((num & (1<<i))!=0)temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};