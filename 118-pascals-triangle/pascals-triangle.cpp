class Solution {
public:
    vector<int> row_gen(int row){
        long long result=1;
        vector<int>ans(1,1);
        for(int i=1;i<row;i++){
            result*=(row-i);
            result/=(i);
            ans.push_back(result);
        }
        return ans;
        
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(row_gen(i));
        }
        return ans;
    }
};