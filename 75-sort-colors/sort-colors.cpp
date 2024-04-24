class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s=0,e=nums.size()-1,move=0;
        while(move<=e){
            if(nums[move]==0)swap(nums[move++],nums[s++]);
            else if(nums[move]==1)move++;
            else if(nums[move]==2)swap(nums[move],nums[e--]);
        }
    }
};