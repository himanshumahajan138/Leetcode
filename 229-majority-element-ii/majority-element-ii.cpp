class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0,count2=0,ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<n;i++){
            if(count1==0&&nums[i]!=ele2){
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0&&nums[i]!=ele1){
                count2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)count1++;
            else if(nums[i]==ele2)count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1=count2=0;
        for(auto x:nums){
            if(x==ele1)count1++;
            else if(x==ele2)count2++;
        }
        int mini=int(n/3);
        nums={};
        if(count1>mini) nums.push_back(ele1);
        if(count2>mini) nums.push_back(ele2);
        return nums;
    }
};