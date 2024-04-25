const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int calculate(string&s,int&k){
        vector<int> next(27, 0) ;
        vector<int> curr(27, 0);
       
        for(int index = s.length()-1 ; index>=0 ; index--)
        {
            for(int prev = 0 ; prev<= 26 ; prev++)
            {
                int op1 = 0 + next[prev];
                int op2 = 0 ;

               if(prev == 26)
               op2 = 1 + next[s[index]-'a'];
               else if(abs(s[index]-'a' - prev) <= k)
               op2 = 1 + next[s[index]-'a'];

               curr[prev] = max(op1 , op2);
            }
            next = curr;
        }

       return max(curr[s[0]-'a'] , curr[26]);
    }

    int longestIdealString(string s, int k) {
        return calculate(s,k);


    }
};