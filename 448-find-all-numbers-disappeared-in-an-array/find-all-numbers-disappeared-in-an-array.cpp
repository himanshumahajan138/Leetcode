auto init = []()
{ ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int t=abs(nums[i])-1;
            nums[t]=nums[t]>0? -nums[t] : nums[t];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        return ans;
    }
};