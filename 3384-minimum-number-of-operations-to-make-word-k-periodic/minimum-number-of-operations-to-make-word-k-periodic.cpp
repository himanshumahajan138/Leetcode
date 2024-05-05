class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int>count;
        
        for (int i = 0; i < word.length(); i += k) {
            string seg = word.substr(i, k);
            ++count[seg];
        }
        
        int maxcount = 0;
        for (auto& it : count) {
            maxcount = max(maxcount, it.second);
        }
        
        return (word.length()/k)-maxcount;
    }
};