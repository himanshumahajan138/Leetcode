class Solution {
public:
    int findLucky(vector<int>& arr) {
        // First pass: encode frequency counts in upper bits
        for (int num : arr) {
            int index = num & 1023; // Extract original value (lower 10 bits)
            if (index - 1 < arr.size()) {
                // Only update if the target index is within bounds
                arr[index - 1] += (1 << 10); // Add 1024 to encode one occurrence
            }
        }

        int ans = -1;
        // Second pass: decode and check for lucky numbers
        for (int i = 0; i < arr.size(); ++i) {
            int freq = arr[i] >> 10;  // Get frequency from higher bits
            int val = i + 1;          // Value this index represents
            if (freq == val) {
                ans = val; // Keep updating to get the largest lucky integer
            }
        }

        return ans;
    }
};