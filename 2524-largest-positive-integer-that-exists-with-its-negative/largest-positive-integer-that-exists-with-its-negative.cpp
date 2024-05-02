const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;
        while (l < r && nums[l] < 0 && nums[r] > 0) {
            if (abs(nums[l]) == nums[r]) return nums[r];
            if (abs(nums[l]) > nums[r]) l++;
            else r--;
        }

        return -1;
    }
};