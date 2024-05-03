const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        for(int i=n-1 ; i>=0 ; --i){
            if((num[i]-'0') & 1)return num.substr(0,i+1);
        }
        return "";
    }
};