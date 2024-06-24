class Solution {
public:
    int minKBitFlips(vector<int>& A, int K, int res = 0, int flips = 0) {
        for (auto i = 0; i < A.size(); ++i) {
            if (A[i] == flips % 2) {
                if (i > A.size() - K)
                    return -1;
                ++res, ++flips, A[i] -= 2;
            }
            if (i >= K - 1 && A[i - K + 1] < 0)
                --flips, A[i - K + 1] += 2;
        }
        return res;
    }
};