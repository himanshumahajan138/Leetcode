class Solution {
public:
    int minCost(string col, vector<int>& time) {
        int n = col.size(), sum = 0;
        
        for (int i = 1; i < n; i++) {
            if (col[i] == col[i - 1]) {
                sum += min(time[i], time[i - 1]);
                time[i] = max(time[i], time[i - 1]);
            }
        }
        return sum;
    }
};