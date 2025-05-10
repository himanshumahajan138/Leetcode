class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        
        long long nums1_sum = 0, nums2_sum = 0;
        long long nums1_zeroes = 0, nums2_zeroes = 0;

        for (int x : nums1) {
            if (x == 0) {
                nums1_zeroes++;
                nums1_sum++; // Replace 0 with 1
            } else {
                nums1_sum += x;
            }
        }

        for (int x : nums2) {
            if (x == 0) {
                nums2_zeroes++;
                nums2_sum++; // Replace 0 with 1
            } else {
                nums2_sum += x;
            }
        }

        if ((nums1_zeroes == 0 && nums2_sum > nums1_sum) ||
            (nums2_zeroes == 0 && nums1_sum > nums2_sum))
            return -1;

        return max(nums1_sum, nums2_sum);
    }
};