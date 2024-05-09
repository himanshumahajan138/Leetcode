class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        if(n==1)return happiness[0];
        
        //edge case if k==n simply add 0 in begin() for overflow index error , very clever
        if (k==n){
            happiness.insert(happiness.begin(),0);
            ++n;
        }
        
        
        sort(happiness.begin(),happiness.end());
        
        int i=0,temp=k;
        long long sum=0;

        while(k-- && i!=temp){
            sum+=happiness[n-1-i];
            happiness[n-i-2] = happiness[n-i-2]-(i+1) >= 0 ? happiness[n-i-2]-(i+1) : 0 ;
            ++i;
        }
        return sum;
    }
};