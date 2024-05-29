const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int numSteps(string& s) {
        int ones = 0, last_one = 0;
        for (auto i = 1; i < s.size(); ++i)
            if (s[i] == '1') {
                last_one = i;
                ++ones;
            }
        return s.size() - 1 + (last_one - ones) + (last_one ? 2 : 0);
    }
};