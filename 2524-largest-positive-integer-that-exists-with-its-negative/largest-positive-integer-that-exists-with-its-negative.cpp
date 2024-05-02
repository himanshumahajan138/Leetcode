const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0)
                mpp[nums[i]]++;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0 && mpp[-nums[i]] != 0)
                maxi = max(nums[i], maxi);
        }
        return maxi < 0 ? -1 : maxi;
    }
};