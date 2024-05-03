const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp,mpp1 ;
        
        for(int i = 0 ; i< s.length() ; ++i){
            if((mpp.find(s[i])==mpp.end()) && mpp1.find(t[i])==mpp1.end()){
                mpp[s[i]]=t[i];
                mpp1[t[i]]=s[i];
                continue;
            }
            if(mpp[s[i]]!=t[i] && mpp1[t[i]]!=s[i] )return false;
        }
        return true;
    }
};