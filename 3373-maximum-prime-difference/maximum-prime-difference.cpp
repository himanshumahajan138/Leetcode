class Solution {
public:
    
         bool prime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int maxd = 0;
        int minprime = -1, maxprime = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (prime(nums[i])) {
                if (minprime == -1) {
                    minprime = i;
                }
                maxprime = i;
            }
        }

        if (minprime != -1 && maxprime != -1) {
            maxd = maxprime - minprime;
        }

        return maxd;
    }
};