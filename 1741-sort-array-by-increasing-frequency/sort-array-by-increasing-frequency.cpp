class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int cnt[201] = {};
        for (auto n : nums)
            ++cnt[n + 100];
        sort(begin(nums), end(nums), [&](int a, int b) {
            return cnt[a + 100] == cnt[b + 100] ? a > b
                                                : cnt[a + 100] < cnt[b + 100];
        });
        return nums;
    }
};