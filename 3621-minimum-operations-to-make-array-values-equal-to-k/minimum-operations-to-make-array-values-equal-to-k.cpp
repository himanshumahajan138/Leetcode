class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int mini = *min_element(nums.begin(), nums.end());
            if (mini < k) return -1;

            bitset<100001> st;
            for (int i : nums) 
                if (i > k) st.set(i);
                
            return st.count();
        }
    };