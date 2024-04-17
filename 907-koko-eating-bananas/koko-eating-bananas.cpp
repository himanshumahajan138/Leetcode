class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(auto x : piles){
            maxi=max(maxi,x);
        }
        int low=0,high=maxi,ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int h_need=0;
            if(mid == 0) {
                low = mid + 1; // Skip this iteration
                continue;
            }
            for(int i=0;i<piles.size();i++){
                h_need+=ceil(1.0*piles[i]/mid);
            }
            if(h_need<=h){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
static const auto __optimize__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();