const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int count=0;
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]=='(')
                count++;
            else
                count--;
                
            if((count==1 && s[i]=='(') || (count==0 && s[i]==')')) 
                continue;
            else
                res+=s[i];
        }
        return res;
    }
};