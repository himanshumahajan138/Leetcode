const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0 ; i<s.size()/2; ++i){
            swap(s[i],s[s.size()-i-1]);
        }
    }
};