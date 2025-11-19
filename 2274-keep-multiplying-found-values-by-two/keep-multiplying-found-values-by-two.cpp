class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bitset<1001> seen=0;
        for(int x: nums)
            seen[x]=1;
        int x=original;
        while(x<=1000){
            if (seen[x]) x*=2;
            else break; 
        }
        return x;
    }
};