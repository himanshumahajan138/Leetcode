class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>record;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int rem = target-num;
            if(record.find(rem)!=record.end()){
                return{record[rem],i};
            }
            record.insert({num,i});
        }
        return {-1,-1};
    }
};