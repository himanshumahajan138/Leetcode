const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    double ans = DBL_MAX;
    int sum = 0;
    vector<pair<double, int>> w;
    priority_queue<int> s;
    for (int i = 0; i < quality.size(); ++i)
      w.emplace_back((double)wage[i] / quality[i], quality[i]);
    ranges::sort(w);
    for (const auto& [wPerQ, q] : w) {
      s.push(q);
      sum += q;
      if (s.size() > k)
        sum -= s.top(), s.pop();
      if (s.size() == k)
        ans = min(ans, sum * wPerQ);
    }
    return ans;}
};