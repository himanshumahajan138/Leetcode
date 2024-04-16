class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int element=nums[i];
            if(element>=1 && element<=n){
                int correctplace=element-1; 
                if(element!=nums[correctplace]){
                    swap(nums[i],nums[correctplace]);
                    i--; //this is to again check back till we get correct element at i position
                }
            }
        }

        //checking which element is not in correct place 
        for(int i = 0 ;i<n;i++){
            if(nums[i] != i+1)return i+1; 
        }
        return n+1; //means the element is not is array and every element in array is in correct order so next first missing +ve number will be size of array + 1 ;
    }
};