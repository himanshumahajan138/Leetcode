const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int>mpp;
        for(int i=0 ; i<score.size() ; ++i){
            mpp[score[i]]=i;
        }
        sort(score.begin(),score.end(),greater<int>());
        vector<string>ranks;
        for(int i=0 ; i<score.size() ; ++i){
            if(i==0)ranks.push_back("Gold Medal");
            else if(i==1)ranks.push_back("Silver Medal");
            else if(i==2)ranks.push_back("Bronze Medal");
            else ranks.push_back(to_string(i+1));
        }
        vector<string>ans(score.size());
        for(int i=0 ; i<score.size() ; ++i){
            ans[mpp[score[i]]]=ranks[i];
        }
        return ans;
    }
};