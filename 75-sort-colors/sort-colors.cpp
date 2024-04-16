class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,e=nums.size()-1,i=0;
        while(i<=e){
            if(nums[i]==0)swap(nums[s++],nums[i++]);
            else if(nums[i]==1) i++;
            else if(nums[i]==2)swap(nums[i],nums[e--]);
        }
    }
};