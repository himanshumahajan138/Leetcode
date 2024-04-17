class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>ans; vector<int>f;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    nums2[j]=INT_MIN;
                    ans.insert(nums1[i]);     
                }
            }
        }
        f.assign(ans.begin(),ans.end());
        return f;
    }
};