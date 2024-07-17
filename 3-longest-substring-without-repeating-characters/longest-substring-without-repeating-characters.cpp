class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();
        int l=0,r=0;
        vector<int>check(256,-1);
        int ans=0;
        while(r<n){
            if(check[s[r]]!=-1){
                if(check[s[r]]>=l){
                    l=check[s[r]]+1;
                }
            }
            check[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans ;
    }
};