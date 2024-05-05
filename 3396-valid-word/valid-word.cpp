class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3)return false;
        int v=0,a=0;
        for(auto ch : word){
            if(ch=='@' || ch=='#' || ch=='$')return false;
            ch=tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                ++v;
                continue;
            }
            if(isalpha(ch)){
                ++a;
                continue;
            }
        }
        return (v>0 && a>0) ? true : false ;
    }
};