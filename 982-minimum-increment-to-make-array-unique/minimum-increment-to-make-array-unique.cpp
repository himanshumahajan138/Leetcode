class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        map<int,int>mpp;
        for(auto x : nums)++mpp[x];
        int cnt=0;
        for(int i=0; i<mpp.size() ; ++i){
            if(mpp[i]>1){
                int val = mpp[i]-1;
                mpp[i]=1;
                mpp[i+1]+=val;
                cnt+=val;
            }
        }
        return cnt;
    }
};