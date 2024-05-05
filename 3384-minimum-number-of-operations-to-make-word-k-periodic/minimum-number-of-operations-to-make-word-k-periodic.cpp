const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        const int n = word.length();
        int m = 0;
        unordered_map<string, int> have;
        for (int i = 0; i < n; i += k) {
            m = max(m, ++have[word.substr(i, k)]);
        }
        return n / k - m;
    }
};