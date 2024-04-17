class Solution {
public:
    bool possible(vector<int>& weights, int days,int cap){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                day+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day<=days ? true : false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        cin.tie(nullptr) -> sync_with_stdio(false);
        int low=INT_MIN,high=0;
        for(auto x : weights){
            low=max(x,low);
            high+=x;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(weights,days,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};