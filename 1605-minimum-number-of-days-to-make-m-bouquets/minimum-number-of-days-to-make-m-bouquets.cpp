class Solution {
public:

    bool possible(vector<int>& bloomDay, int m, int k,int day){
        int cnt=0,nob=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)cnt++;
            else{
                nob+=(cnt/k);
                cnt=0;
            }
        }
        nob+=(cnt/k);
        return nob>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long n=bloomDay.size();
        if(n<1LL*m*1LL*k)return -1;
        int maxi=INT_MIN,mini=INT_MAX,ans;
        for(auto x:bloomDay){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        while(mini<=maxi){
            int day=mini+(maxi-mini)/2;
            if(possible(bloomDay,m,k,day)){
                ans=day;
                maxi=day-1;
            }
            else{
                mini=day+1;
            }
        }
        return ans;
    }
};