class Solution {
public:
    void generate(int ind, int target, vector<int>& sub, vector<vector<int>>& ans,
                  vector<int>& arr, int n) {
        if (target == 0) {
            ans.push_back(sub);
            return;
        }
        for (int i =ind ; i <= n - 1; i++) {
            if(i>ind && arr[i]==arr[i-1])continue;
            if (arr[i] > target)
                break;
            
                sub.push_back(arr[i]);
                generate(i + 1, target - arr[i], sub, ans, arr, n);
                sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        generate(0, target, sub, ans, candidates, candidates.size());
        return ans;
    }
};