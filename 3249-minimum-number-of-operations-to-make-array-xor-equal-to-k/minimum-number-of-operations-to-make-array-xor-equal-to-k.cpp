class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int XOR = 0 ;
        for(auto x : nums){
            XOR^=x;
        }
        int count =0;
        int temp = XOR ^ k ;
        while(temp!=0){
            temp= temp&temp-1;
            count++;
        }
        return count;
    }
};