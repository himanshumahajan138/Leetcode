const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        for(auto x : s)++mpp[x];
        for(auto x : t)--mpp[x];
        for(auto it : mpp){
            if(it.second!=0)return false;
        }
        return true;
    }
};