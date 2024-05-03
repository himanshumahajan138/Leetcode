const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];

        string prefix = "";
        string prefix1 = "";


        for (int i = 0; i < strs[0].length(); ++i) {
            prefix.push_back(strs[0][i]);

            for (int k=1; k < strs.size(); ++k) {
                prefix1.push_back(strs[k][i]);

                if (prefix != prefix1) {
                    prefix1.pop_back();
                    return prefix1;
                }

                if (k != strs.size() - 1)
                    prefix1.pop_back();
            }
            if(i==strs[0].length()-1 && prefix == prefix1)return prefix;

        }
        return "";
    }
};