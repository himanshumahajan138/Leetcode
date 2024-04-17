class Solution {
public:

    int calculateTh(vector<int>&nums,int mid){
        int th=0;
        for(int i=0;i<nums.size();i++){
            th+=ceil((double)(nums[i])/(double)(mid));
        }
        return th;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int low=1,ans=INT_MIN,high=INT_MIN,n=nums.size();
        if(n>threshold)return -1;
        for(auto x:nums){
            high=max(high,x);
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            int th=calculateTh(nums,mid);
            if(th<=threshold){
                ans=mid;
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};