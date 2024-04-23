static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();


class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        int hash[128] = {0};
        int cnt = 0;
        
        for(int i = 0; i < n; ++i)
        {
            if(s[i] >= 97 && s[i] <= 122)
            {
                if(hash[s[i] - 32] == 0)
                {
                    hash[s[i]]++;
                }
                else
                {
                    if(hash[s[i] - 32] > 0)
                    {
                        if(hash[s[i]] > 0)  cnt--;
                        hash[s[i] - 32] = -1e9;
                        hash[s[i]]++;
                    }
                }
            }
            else
            {
                if(hash[s[i]] == 0 && hash[s[i] + 32] > 0) cnt++;
                hash[s[i]]++;
            }
                                            
        }
        
        return cnt;
    }
};