class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int c=1;
        for(int layer=0;layer<(n+1)/2;layer++){
            for(int i=layer;i<n-layer;i++){
                ans[layer][i]=c++;
            }
            for(int i=layer+1;i<n-layer;i++){
                ans[i][n-layer-1]=c++;
            }
            for(int i=n-layer-2;i>=layer;i--){
                ans[n-layer-1][i]=c++;
            }
            for(int i=n-layer-2;i>layer;i--){
                ans[i][layer]=c++;
            }
        }
        return ans;
    }
};