const static auto initialize = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        int lsum = 0, rsum = 0;
        for (int i = 0; i < k; ++i)
            lsum += arr[i];
        ans = lsum;
        int l = n - 1;
        for (int i = k - 1; i >= 0; --i) {
            lsum -= arr[i];
            rsum += arr[l];
            ans = max(ans, lsum + rsum);
            --l;
        }

        return ans;
    }
};