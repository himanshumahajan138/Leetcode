const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (m < n)
            return -1;
        for (int i = 0; i <= (m - n); ++i) {
            int j = 0;
            while (j < n && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};