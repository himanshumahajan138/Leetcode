const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind = -1;
        for(int i=0 ; i<word.length() ; ++i){
            if(word[i]==ch){
                ind =i;
                break;
            }
        }
        if(ind==-1)return word;
        int i=0;
        while(i<=ind){
            swap(word[i++],word[ind--]);
        }
        return word;
    }
};