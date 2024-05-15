const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for (char ch : s){
            ++mpp[ch];
        }
        map<int,string,greater<int>>hash;
        for(auto it : mpp){
            hash[it.second]+=string(it.second,it.first);
        }
        
        string ans="";
        for(auto it : hash){
            ans+=it.second;
        }
        return ans;
    }
};