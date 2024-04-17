class Solution {
public:

    void generate(int ind, vector<int>&sub ,vector<vector<int>>&ans ,vector<int>&arr , int n){
        ans.push_back(sub);
        for(int i=ind;i<n;i++){   
            if(i>ind && arr[i]==arr[i-1])continue;
            sub.push_back(arr[i]);
            generate(i+1,sub,ans,arr,n);
            sub.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sub;
        vector<vector<int>>ans;
        generate(0,sub,ans,nums,nums.size());
        // sort(ans.begin(),ans.end());
        return ans;
    }
};