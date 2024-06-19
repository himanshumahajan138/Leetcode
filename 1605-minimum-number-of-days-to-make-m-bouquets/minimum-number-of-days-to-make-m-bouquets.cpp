class Solution {
public:

    bool possible(int mid ,int m ,  int k , vector<int>&arr){
        int cnt=0,nb=0;
        for(int i=0 ; i<arr.size() ; ++i){
            if(mid>=arr[i])++cnt;
            else {
                nb+=(cnt/k);
                cnt=0;
            }
        }
        nb+=(cnt/k);
        return nb>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(1LL*m*k))return -1;
        int maxi=INT_MIN,mini=INT_MAX;
        for(auto x:bloomDay){
            maxi=max(maxi,x);
            mini=min(mini,x);
        }
        int l=mini,r=maxi;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(possible(mid,m,k,bloomDay)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;

    }
};