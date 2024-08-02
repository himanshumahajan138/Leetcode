class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total_ones = 0;
        
        // Count the total number of 1s in the array
        for (int num : nums) {
            if (num == 1) {
                ++total_ones;
            }
        }

        // If there are no 1s or the entire array is 1s, no swaps are needed
        if (total_ones == 0 || total_ones == n) {
            return 0;
        }

        // Calculate the maximum number of 1s in any subarray of length total_ones
        int max_ones_in_window = 0;
        int current_ones_in_window = 0;

        // Initial window calculation
        for (int i = 0; i < total_ones; ++i) {
            if (nums[i] == 1) {
                ++current_ones_in_window;
            }
        }

        max_ones_in_window = current_ones_in_window;

        // Slide the window across the array
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == 1) {
                --current_ones_in_window;
            }
            if (nums[(i + total_ones - 1) % n] == 1) {
                ++current_ones_in_window;
            }
            max_ones_in_window = max(max_ones_in_window, current_ones_in_window);
        }

        return total_ones - max_ones_in_window;
    }
};