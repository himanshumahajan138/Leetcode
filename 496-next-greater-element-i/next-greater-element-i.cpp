const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size());
        stack<int>st;
        unordered_map<int,int>mpp;
        for(int i=nums2.size()-1 ; i>=0 ; --i){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            if(st.empty())mpp[nums2[i]]=-1;
            else {
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0 ; i<nums1.size() ; ++i){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};