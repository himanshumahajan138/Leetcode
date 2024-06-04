const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        for(auto ch : s)++mpp[ch];
        int len=0;
        int max_odd_len=1;
        int one_len_odd=0;
        for(auto it : mpp){
            if((it.second & 1)==0){
                len+=it.second;
            }
            else {
                if(it.second==1)++one_len_odd;
                else if(it.second>max_odd_len){
                    len+=(max_odd_len/2)*2;
                    max_odd_len=it.second;
                }
                else len+=(it.second/2)*2;
            }
        }
        if(max_odd_len>1)len+=max_odd_len;
        else if(one_len_odd>0)++len;
        return len;
    }
};