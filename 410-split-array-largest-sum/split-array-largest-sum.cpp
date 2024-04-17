class Solution {
public:
    int split_min_sum(vector<int>&nums,int mid){
        int last_splitted_till=1;
        long long split_sum=0;
        for(int i=0;i<nums.size();i++){
            if(split_sum+nums[i]<=mid){
                split_sum+=nums[i];
            }
            else{
                split_sum=nums[i];
                last_splitted_till++;
            }
        }
        return last_splitted_till;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN,high=0;
        for(auto x:nums){
            low=max(x,low);
            high+=x;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(split_min_sum(nums,mid)>k)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};