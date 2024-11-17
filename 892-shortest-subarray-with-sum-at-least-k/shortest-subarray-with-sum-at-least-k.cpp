class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int shortest = INT_MAX;  // Track shortest valid subarray length
        deque<pair<long long, int>> queue;  // Store (sum, length) pairs
        long long total = 0;     // Track current sum
        int currLen = 0;         // Track current length
        
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (n < 0) {
                if (total + n <= 0) {  // Handle neg. numbers
                    queue.clear();
                    total = 0;
                    currLen = 0;
                    continue;
                } else {
                    auto [removed, removeLen] = queue.back(); // Merge neg. number
                    queue.pop_back();
                    long long curr = n + removed;
                    int stackLength = 1 + removeLen;
                    
                    while (!queue.empty() && curr < 0) { // Keep merging non-neg. sum
                        auto [removed2, removeLen2] = queue.back();
                        queue.pop_back();
                        curr += removed2;
                        stackLength += removeLen2;
                    }
                    
                    total += n;
                    queue.push_back({curr, stackLength});
                    currLen += 1;
                }
            } else {
                queue.push_back({n, 1}); // Handle pos. number
                total += n;
                currLen += 1;
            }
            
            while (!queue.empty() && total >= k) { // Check if cur. window sum exceeds k
                shortest = min(shortest, currLen);
                auto [removed, removeLen] = queue.front();
                queue.pop_front();
                total -= removed;
                currLen -= removeLen;
            }
        }
        
        return shortest <= nums.size() ? shortest : -1;
    }
};