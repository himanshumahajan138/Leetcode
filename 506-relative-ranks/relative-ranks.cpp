const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        unordered_map<int, int> mpp;

        for (int i = 0; i < score.size(); ++i) {
            mpp[score[i]] = i;
        }

        sort(score.begin(), score.end(), greater<int>());

        vector<string> ranks(score.size());

        for (int i = 0; i < score.size(); ++i) {
            if (i == 0)
                ranks[mpp[score[i]]] = "Gold Medal";
            else if (i == 1)
                ranks[mpp[score[i]]] = "Silver Medal";
            else if (i == 2)
                ranks[mpp[score[i]]] = "Bronze Medal";
            else
                ranks[mpp[score[i]]] = to_string(i + 1);
        }
        
        return ranks;
    }
};