const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int climbStairs(int n) {
        int l=1;
        int ll=1;
        for(int i=2;i<=n;++i){
            int c=l+ll;
            ll=l;
            l=c;
        }
        return l;
    }
};