const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> mono;
        int n = prices.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            while (!mono.empty() && mono.top() > prices[i]) {
                mono.pop();
            }
            if (!mono.empty()) {
                ans[i] = prices[i] - mono.top();
            } else {
                ans[i] = prices[i];
            }
            mono.push(prices[i]);
        }

        return ans;
    }
};
