class Solution {
public:
    bool func(string& s ,int start,int end){
        if(start>end){
            return true;
        }

        if(!(isalnum(s[start]))) return func(s,start+1,end);
        if(!(isalnum(s[end]))) return func(s,start,end-1);

        if(isalnum(s[start]) && isalnum(s[end])){
            return tolower(s[start])==tolower(s[end]) ? func(s,start+1,end-1) : false;
        }
        return false;
    }
    bool isPalindrome(string s) {
        return func(s,0,s.length()-1);
    }
};