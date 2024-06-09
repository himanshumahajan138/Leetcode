
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int prefix=0;
        int cnt=0;
        for(int i=0; i<nums.size() ; ++i){
            prefix+=nums[i];
            int rem=prefix%k;
            if(rem<0)rem+=k;
            if(mpp[rem]!=0){
                cnt+=mpp[rem];
            }
            ++mpp[rem];
        }
        return cnt;
    }
};