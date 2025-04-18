class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string res = "";
        int i = 0;

        while (i < prev.size()) {
            int count = 1;
            while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                i++;
                count++;
            }
            res += to_string(count) + prev[i];
            i++;
        }

        return res;
    }
};