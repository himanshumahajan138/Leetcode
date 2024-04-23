class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> low;
        unordered_set<char> up;
        int c = 0;

        for (char i : word) {
            if (islower(i)) {
                low.insert(i);
            } else {
                up.insert(i);
            }
        }

        for (char i : low) {
            if (up.count(static_cast<char>(toupper(i)))) {
                c++;
            }
        }

        return c;
    }
};