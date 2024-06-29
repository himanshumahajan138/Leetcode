const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void dfs(int start,vector<int>&visited,vector<int>adj[]){
        visited[start]=1;
        for(auto a:adj[start]){
            if(!visited[a]){
                dfs(a,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>adj[v];
        for(int i =0;i<v ; ++i){
            for(int j = 0 ; j<v ; ++j){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt=0;
        vector<int>visited(v,0);
        for(int i=0 ; i<v ; ++i){
            if(!visited[i]){
                ++cnt;
                dfs(i,visited,adj);
            }
        }
        return cnt;
    }
};