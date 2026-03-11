// Title: Complement of Base 10 Integer
            // Difficulty: Easy
            // Language: C++
            // Link: https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int mask = n;
        for (int i = 0; i <= 4; i++)
            mask |= mask >> (1 << i);
        return ~n & mask;
    }
};
