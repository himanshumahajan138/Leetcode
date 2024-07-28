class Solution {
public:
    int stepsTime(int steps, int time, int change) {
        int res = 0;
        while (--steps) {
            res += time;
            if ((res / change) % 2)
                res = (res / change + 1) * change;
        }
        return res + time;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> al(n + 1);
        vector<int> minSteps(n + 1, 10001);
        for (auto& e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        int step = -1;
        vector<int> q({1});
        while (!q.empty() && ++step <= minSteps[n] + 1) {
            vector<int> q1;
            for (int i : q) {
                if (step == minSteps[i] || step > minSteps[i] + 1)
                    continue;
                minSteps[i] = min(minSteps[i], step);
                if (i == n && step > minSteps[n])
                    return stepsTime(step, time, change);
                for (int j : al[i])
                    q1.push_back(j);
            }
            swap(q, q1);
        }
        return stepsTime(minSteps[n] + 2, time, change);
    }
};