class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lfreq(26,0),ufreq(26,0);
        int count=0;
        for(char ch:word)
        {
            if(isupper(ch)) ufreq[ch-'A']++;
            if(islower(ch)) lfreq[ch-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(ufreq[i]>0 && lfreq[i]>0) count++;
        }
        return count;
    }
};