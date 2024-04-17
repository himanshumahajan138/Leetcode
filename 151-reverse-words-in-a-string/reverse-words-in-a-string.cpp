const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = n - 1;
        string ans = "", word = "";
        while (i != -1) {
            if (s[i] == ' ') {
                if (word != "")
                    ans += word + " ";
                word = "";
                i--;
            } else {
                word = s[i] + word;
                i--;
                if (i == -1)
                    ans += word;
            }
        }
        int len = ans.length();
        if (ans[len - 1] == ' ')
            ans = ans.substr(0, len - 1);
        return ans;
    }
};