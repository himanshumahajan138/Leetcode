class Solution {
public:
    void generate(int i, int k, int sum, int n, vector<int>& sub,
                  vector<vector<int>>& ans) {
        if(n<k)return;

        if (sub.size()==k){
            if(sum == n)ans.push_back(sub);
            return;
        }

        if(i==10) return ;
        
        sub.push_back(i);
        sum += i;
        generate(i+1, k, sum, n, sub, ans);
        sub.pop_back();
        sum -= i;
        generate(i + 1, k, sum, n, sub, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>sub;
        vector<vector<int>>ans;
        generate(1,k,0,n,sub,ans);    
        return ans;
    }
};