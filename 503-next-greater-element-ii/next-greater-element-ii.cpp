const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        stack<int>st;
        for(int i=(2*nums.size())-1 ; i>=0 ; --i){
            while(!st.empty() && st.top()<=nums[i % nums.size()]){
                st.pop();
            }
            ans[i % nums.size()] = st.empty() ? -1 : st.top();
            st.push(nums[i % nums.size()]);
        }
        return ans;
    }
};