class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle(n);
        for (int i = 0; i < n; ++i)
            circle[i] = i + 1;

        int winnerIndex = 0;
        while (n > 1) {
            winnerIndex = (winnerIndex + k - 1) % n;
            --n;
            circle.erase(circle.begin() + winnerIndex);
        }

        return circle[0];
    }
};