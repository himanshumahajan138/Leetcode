class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        if(nums.size()<3){
            return nums.size();
        }
        for(int i=0,a=2;i<nums.size();i++){
            if(nums.size()-1<a) break;
            if(nums[i]==nums[a]){
                nums[i]=INT_MAX;
                count++;
            }
            a++;
        }
        sort(nums.begin(),nums.end());        
        return nums.size()-count;
    }
};