class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==0)++zero;
            else if(nums[i]==1)++one;
            else ++two;
        }
        nums.assign(zero,0);
        nums.insert(nums.end(),one,1);
        nums.insert(nums.end(),two,2);

    }
};