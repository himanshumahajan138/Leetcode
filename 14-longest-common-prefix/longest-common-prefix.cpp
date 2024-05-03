const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());
        string prefix = "";

        for (int i = 0; i < strs[0].length(); ++i) {

            if (strs[0][i] != strs[strs.size() - 1][i])
                return prefix;

            prefix.push_back(strs[0][i]);
        }
        return prefix;
    }
};