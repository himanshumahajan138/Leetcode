const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool rotateString(string &s, string goal) {
        return s.length()==goal.length() && (s+s).find(goal)!=string::npos;
    }
};