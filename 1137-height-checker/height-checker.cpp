
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>temp=heights;
        sort(temp.begin(),temp.end());
        int cnt = 0;
        for(int i=0 ; i<temp.size() ; ++i){
            if(temp[i]!=heights[i])++cnt;
        }
        return cnt;
    }
};