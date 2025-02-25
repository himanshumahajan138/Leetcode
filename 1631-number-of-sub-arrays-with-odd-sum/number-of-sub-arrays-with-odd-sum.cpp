class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1000000007;
        int odd = 0, even = 1; // even is initialized to 1 because prefix sum of 0 is even
        int result = 0;
        int prefixSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum ^= arr[i]; // Toggle between odd and even using XOR
            if (prefixSum & 1) {
                // If prefixSum is odd, add the number of even prefix sums to result
                result = (result + even) % MOD;
                odd++; // Increment odd prefix sum count
            } else {
                // If prefixSum is even, add the number of odd prefix sums to result
                result = (result + odd) % MOD;
                even++; // Increment even prefix sum count
            }
        }

        return result;
    }
};