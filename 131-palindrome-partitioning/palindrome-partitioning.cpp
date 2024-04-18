class Solution {
public:

    bool is_palindrome(string&s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])return false ;
        }
        return true;
    }

    void generate(int i,string&s,vector<string>&sub,vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(sub);
            return;
        }
        for(int j=i ; j<s.size() ; j++){
            if(is_palindrome(s,i,j)){
                sub.push_back(s.substr(i,j-i+1));
                generate(j+1,s,sub,ans);
                sub.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans ;
        vector<string>sub;
        generate(0,s,sub,ans);
        return ans ;
    }
};