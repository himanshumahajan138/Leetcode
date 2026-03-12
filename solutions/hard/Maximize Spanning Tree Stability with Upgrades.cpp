// Title: Maximize Spanning Tree Stability with Upgrades
            // Difficulty: Hard
            // Language: C++
            // Link: https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/

        return dsu.components == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // Early check: mandatory edges alone must not form a cycle
        {
            DSU dsu(n);
            for (auto &e : edges) {
                if (e[3] == 1) {
                    if (!dsu.unite(e[0], e[1])) return -1;
                }
            }
        }

        int low = 1, high = 200000, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAchieve(n, edges, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
