class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>temp;
        if(n>0&&n<501&&nums.size()==2*n){
            for(int i=0;i<n;i++){
                if(nums[i]>0&&nums[i]<1001){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[n+i]);
                }
            }
        }
        nums=temp;
        return nums;
    }
};