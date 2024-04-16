class Solution {
public:
    void generate(int o,int c ,string &s, vector<string>&ans){
        if(o==0 && c==0){
            ans.push_back(s);
            return;
        }
        if(o>0){
            s.push_back('(');
            generate(o-1,c,s,ans);
            s.pop_back();
        }
        if(c>0){
            if(o<c){
                s.push_back(')');
                generate(o,c-1,s,ans);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        generate(n,n,s,ans);
        return ans;
    }
};