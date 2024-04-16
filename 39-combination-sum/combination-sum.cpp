class Solution {
public:
    void generate(int i, int target, vector<int>& sub, vector<vector<int>>& ans,
                  vector<int>& candidates, int n) {
        
        if (i == n) {
            if(target==0)ans.push_back(sub);
            return;
        }
        if(candidates[i]<=target){    // means we can add this elementto sum till target
            sub.push_back(candidates[i]);   //take condition
            generate(i,target-candidates[i],sub,ans,candidates,n); //if we take 
            sub.pop_back(); //not take also its meant for backtracking means we have to revert changes that was made previously
        }
        generate(i+1,target,sub,ans,candidates,n);   //if we dont take the element bcoz its bigger than the target required 

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>sub;
        generate(0,target,sub,ans,candidates,candidates.size());
        return ans;
    }
};