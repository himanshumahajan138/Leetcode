const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (auto x : nums) {
            ones = (ones ^ x) & (~twos); // add to ones if not present in twos
            twos = (twos ^ x) & (~ones); // add to twos if present in ones, then
            // next time it gets deleted from ones
            // because it will be present in twos we can also
            // use third bucket but its usefull if single number
            // occured twice and other thrice
        }
        return ones;
    }
};