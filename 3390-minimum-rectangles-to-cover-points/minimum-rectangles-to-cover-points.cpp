class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<pair<int,int>> arr;
        for(auto x:points){
            arr.push_back({x[0],x[1]});
        }
        sort(arr.begin(),arr.end());
        int ans=1;
        int cur=arr[0].first;
        for(int i=1;i<arr.size();i++){
            if(arr[i].first<=cur+w){continue;}
            else{
                ans++;
                cur=arr[i].first;
            }
        }
        return ans;
    }
};