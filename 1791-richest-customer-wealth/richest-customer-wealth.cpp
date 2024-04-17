class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(int i=0;i<accounts.size();i++){
            int temp=0;
            for(int j=0;j<accounts[i].size();j++){
                temp+=accounts[i][j];
            }
            if(temp>ans) ans=temp;
        }
        return ans;
    }
};