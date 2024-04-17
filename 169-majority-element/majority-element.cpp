class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(auto it:nums){
            if(it==candidate) count++;
            else if(count==0) candidate=it;
            else{ count--;}
        }
        return candidate;
    }
};