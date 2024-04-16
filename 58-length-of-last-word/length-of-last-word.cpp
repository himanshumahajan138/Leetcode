class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int lastcnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=32){
                cnt++;
                lastcnt=cnt;
            }
            else {
                //lastcnt=cnt;
                cnt=0;
            }
        }

        return lastcnt;
    }
};