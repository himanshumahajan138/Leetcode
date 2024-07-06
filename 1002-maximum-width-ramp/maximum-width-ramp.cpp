class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        
        // First pass: build a stack of indices where each corresponding value in nums is in decreasing order
        for (int i = 0; i < nums.size(); ++i) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        
        int maxo = 0;
        
        // Second pass: traverse from the end to the start to find the maximum width ramp
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                maxo = max(maxo, i - st.top());
                st.pop();
            }
        }
        
        return maxo;
    }
};
