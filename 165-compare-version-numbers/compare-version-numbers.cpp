const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int n1 = version1.length(), n2 = version2.length();

        while (i1 < n1 || i2 < n2) {
            int num1 = 0, num2 = 0;

            while (i1 < n1 && version1[i1] != '.') {
                num1 = num1 * 10 + (version1[i1] - '0');
                ++i1;
            }

            while (i2 < n2 && version2[i2] != '.') {
                num2 = num2 * 10 + (version2[i2] - '0');
                ++i2;
            }

            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;

            ++i1;
            ++i2;
        }

        return 0;
    }
};