class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dip=-1,n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                dip=i;
                break;
            }
        }
        if(dip==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[dip]){
                int temp=nums[i];
                nums[i]=nums[dip];
                nums[dip]=temp;
                break;
            }
        }
        reverse(nums.begin()+dip+1,nums.end());
    }
};