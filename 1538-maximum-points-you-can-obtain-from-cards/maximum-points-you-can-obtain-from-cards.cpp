class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int ans=0;
        int n=arr.size();
        if(k==n){
            for(auto a :arr)ans+=a;
            return ans;
        }
        else{
            int lsum =0,rsum=0; 
            for(int i=0 ; i<k ; ++i)lsum+=arr[i];
            ans=lsum;
            int l=n-1;
            for(int i=k-1;i>=0;--i){
                lsum-=arr[i];
                rsum+=arr[l];
                ans=max(ans,lsum+rsum);
                --l;
            }
        }
        return ans;
    }
};