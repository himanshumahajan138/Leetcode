class Solution {
public:
    int lower_bound(vector<int>&arr,int target,int low ,int high,int ans){
        if(low>high)return ans;
        int mid = low+(high-low)/2;
        if(arr[mid]>=target){
            ans=mid;
            return lower_bound(arr,target,low,mid-1,ans);
        }
        else return lower_bound(arr,target,mid+1,high,ans);
    }
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,ans=nums.size();
        return lower_bound(nums,target,low,high,ans);
    }
};