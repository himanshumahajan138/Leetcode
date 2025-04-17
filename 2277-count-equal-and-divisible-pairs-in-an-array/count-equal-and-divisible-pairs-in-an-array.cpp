struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename K, typename V>
using safe_umap = unordered_map<K, V, custom_hash>;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int pairs = 0;
        safe_umap<int, vector<int>> mpp;
        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]].push_back(i);
        vector<int> divisors;
        for (int d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                divisors.push_back(d);
                if (d != k / d)
                    divisors.push_back(k / d);
            }
        }
        for (auto& [key, vec] : mpp) {
            safe_umap<int, int> mpp;
            for (int i : vec) {
                int gcdd = gcd(i, k);
                int add = k / gcdd;
                pairs += mpp[add];
                for (int d : divisors) {
                    if (i % d == 0)
                        mpp[d]++;
                }
            }
        }
        return pairs;
    }
};