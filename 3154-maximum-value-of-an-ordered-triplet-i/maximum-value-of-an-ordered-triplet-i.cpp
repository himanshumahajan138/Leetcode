class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxTriplet = 0, maxElement = 0, maxDiff = 0;
        for (long num : nums) {
            maxTriplet = max(maxTriplet, maxDiff * num);
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, num);
        }
        return maxTriplet;
    }
};