const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void generate(int i, vector<int>& sub, vector<int>& nums,
                  vector<vector<int>>& ans, int n) {
        if (i == n) {
            ans.push_back(sub);
            return;
        }
        generate(i + 1, sub, nums, ans, n);

        sub.push_back(nums[i]);
        generate(i + 1, sub, nums, ans, n);
        sub.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        generate(0, sub, nums, ans, nums.size());
        return ans;
    }
};