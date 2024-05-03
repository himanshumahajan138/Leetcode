const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.length()-1;
        while(i>=0){
            if((num[i]-'0') & 1)return num.substr(0,i+1);
            --i;
        }
        return "";
    }
};