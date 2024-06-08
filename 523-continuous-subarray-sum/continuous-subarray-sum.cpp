const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int prefix=0;
        for(int i=0 ; i<nums.size() ; ++i){
            prefix+=nums[i];
            prefix%=k;

            if(((prefix) == 0) && i>0)return true;

            if(mpp.find(prefix)!=mpp.end()){
                if(i-mpp[prefix] > 1)return true;
            }
            else mpp[prefix]=i;
        }
        return false;
    }
};