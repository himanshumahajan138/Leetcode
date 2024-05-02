const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR=0;
        for(auto x : nums){
            XOR^=x;
        }
        int temp = (XOR & (XOR-1))^XOR;
        int a=0,b=0;
        for(auto x :nums){
            if(x & temp)a^=x;
            else b^=x;
        }
        return {a,b};
        
    }
};