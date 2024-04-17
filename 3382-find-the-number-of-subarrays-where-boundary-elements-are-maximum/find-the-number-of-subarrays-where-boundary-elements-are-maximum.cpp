const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        long ans = 0;
        for(auto it: nums){
            m[it]++;
            ans += m[it];
            for(auto t: m){
                if(t.first<it) m.erase(t.first);
                else break;
            }
        }
        return ans;
    }
};