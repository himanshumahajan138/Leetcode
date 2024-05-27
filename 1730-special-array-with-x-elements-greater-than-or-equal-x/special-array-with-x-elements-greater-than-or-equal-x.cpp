const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums[0]>=n)return n;
        int l=1,h=n-1;

        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>=(n-mid) && nums[mid-1]<(n-mid)){
                return n-mid;
            }
            else if(nums[mid]<(n-mid))l=mid+1;
            else h=mid-1;
        }
    return -1;
    }
};