const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    std::string makeGood(std::string s) {
        std::stack<char> stack;
        
        for (char c : s) {
            if (!stack.empty() && std::abs(c - stack.top()) == 32) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        
        std::string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};