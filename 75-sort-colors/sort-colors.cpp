class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x=0,y=nums.size()-1,z=0;
        while(z<=y){
            if(nums[z]==0)swap(nums[z++],nums[x++]);
            else if(nums[z]==1)z++;
            else if(nums[z]==2)swap(nums[z],nums[y--]);
        }
    }
};