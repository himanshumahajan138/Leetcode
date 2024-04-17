class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1=0,xor2=0;
        for(int i = 0 ; i<n ; i++){
            xor2=xor2^nums[i];
            xor1=xor1^(i+1);
        }
        return (xor2^xor1);
    }
};