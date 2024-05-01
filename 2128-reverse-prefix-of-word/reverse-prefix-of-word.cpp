const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind;
        for(int i=0 ; i<word.length() ; ++i){
            if(word[i]==ch){
                string sub = word.substr(0,i+1);
                string next = word.substr(i+1,word.length()-i-1);
                reverse(sub.begin(),sub.end());
                return sub+next;
            }
        }
        return word;
    }
};