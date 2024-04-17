class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int l=0,r=n-1;
        int score=0;
        for(int l=0,r=n-1;l<=n/2;l++){
            if(l==r)return score;
            if(l+1==r){
                return score+=abs((int)s[l]-(int)s[r]);
            }
            score+=abs((int)s[l]-(int)s[l+1]);
            score+=abs((int)s[r]-(int)s[r-1]);
            r--;   
        }
        return score;
    }
};