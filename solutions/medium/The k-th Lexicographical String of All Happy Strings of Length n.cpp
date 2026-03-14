// Title: The k-th Lexicographical String of All Happy Strings of Length n
            // Difficulty: Medium
            // Language: C++
            // Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
public:
    string getHappyString(int n, int k) {

        int total = 3 * (1<<(n-1));
        if(k>total) return "";

        k--;
        string res="";
        char last='\0';

        for(int pos=0;pos<n;pos++){

            int branch=1<<(n-pos-1);

            vector<char> choices;
            for(char c:{'a','b','c'})
                if(c!=last) choices.push_back(c);

            int idx=k/branch;
            res+=choices[idx];
            last=choices[idx];
            k%=branch;
        }

        return res;
    }
};
