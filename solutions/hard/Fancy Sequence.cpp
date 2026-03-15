// Title: Fancy Sequence
            // Difficulty: Hard
            // Language: C++
            // Link: https://leetcode.com/problems/fancy-sequence/

    
    void append(int val) {
        long long x = (val - b + mod) % mod;
        this->val.push_back((x * modPow(a, mod - 2, mod)) % mod);
    }
    
    void addAll(int inc) {
        b = (b + inc) % mod;
    }
    
    void multAll(int m) {
        a = (a * m) % mod;
        b = (b * m) % mod;
    }
