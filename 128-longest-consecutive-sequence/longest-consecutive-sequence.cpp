class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.size()==0)return 0;
        unordered_set<int>set;
        int start=nums[0],longest=1;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        for(auto x : set){
            if(set.find(x-1)==set.end()){
                int count=1;
                int ele=x;
                while(set.find(ele+1)!=set.end()){
                    count+=1;
                    ele+=1;
                }
                longest=max(count,longest);
            }
        }
        return longest;
    }
};