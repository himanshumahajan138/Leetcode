class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n), al(n);
        function<void(int, int)> dfs = [&](int i, int anc) {
            for (auto j : al[i])
                if (res[j].empty() || res[j].back() != anc) {
                    res[j].push_back(anc);
                    dfs(j, anc);
                }
        };
        for (auto& e : edges)
            al[e[0]].push_back(e[1]);
        for (int i = 0; i < n; ++i)
            dfs(i, i);
        return res;
    }
};