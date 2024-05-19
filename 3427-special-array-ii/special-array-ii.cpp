const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> special(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        if (n < 2) {
            vector<bool> ans(queries.size(), true);
            return ans;
        }

        vector<int> pdiff(n - 1, 0);

        
        for (int i = 0; i < n - 1; ++i) {
            pdiff[i] = ((nums[i] & 1) != (nums[i + 1] & 1)) ? 1 : 0;
        }


        vector<int> ppdiff(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            ppdiff[i + 1] = ppdiff[i] + pdiff[i];
        }


        vector<bool> ans;
        for (auto& query : queries) {
            
            int from = query[0];
            int to = query[1];
            
            if (to == from) {
                ans.push_back(true); 
            } 
            else {
                int expected = to - from;
                int actual = ppdiff[to] - ppdiff[from];
                
                ans.push_back(actual == expected);
            }
        }
        return ans;
    }
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       
        return special(nums,queries);
    }
};