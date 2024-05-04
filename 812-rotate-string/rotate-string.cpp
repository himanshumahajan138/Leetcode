class Solution {
public:
    bool rotateString(string &s, string goal) {
        for(int k=0 ; k<s.length() ; ++k){
            string left=s.substr(0,k+1) ,right=s.substr(k+1,s.length()-(k+1));
            reverse(left.begin(),left.end());
            reverse(right.begin(),right.end());
            string x=left+right;
            reverse(x.begin(),x.end());
            if(x==goal)return true;
        }
        return false;
    }
};