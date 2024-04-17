const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefixSum = 1, n = nums.size();
        vector<int> result(n, 1);
        for (int i = 0; i < n - 1; i++) {
            result[i + 1] = prefixSum * nums[i];
            prefixSum *= nums[i];
        }
        prefixSum = 1;
        for (int i = n - 1; i > 0; i--) {
            result[i - 1] *= prefixSum * nums[i];
            prefixSum *= nums[i];
        }
        return result;
    }
};