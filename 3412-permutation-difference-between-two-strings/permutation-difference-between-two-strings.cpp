const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,int>a;
        unordered_map<char,int>b;
        int i=0;
        for(auto ch : s){
            a[ch]=i;
            ++i;
        }
        i=0;
        for(auto ch : t){
            b[ch]=i;
            ++i;
        }
        
        int ans=0;
        for(auto ch : s){
            ans+=abs(a[ch]-b[ch]);
        }
        return ans;
    }
};