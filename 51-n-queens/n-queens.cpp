const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void place(int col, vector<int>& lr, vector<int>& uld, vector<int>& lld,
               vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (lr[row] == 0 && lld[row + col] == 0 &&
                uld[col - row + n - 1] == 0) {
                lr[row] = 1;
                lld[row + col] = 1;
                uld[col - row + n - 1] = 1;
                board[row][col] = 'Q';
                place(col + 1, lr, uld, lld, board, ans, n);
                lr[row] = 0;
                lld[row + col] = 0;
                uld[col - row + n - 1] = 0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> leftrow(n, 0), upperleftdiagonal(2 * n - 1, 0),
            lowerleftdiagonal(2 * n - 1);
        string s(n, '.');
        vector<string> board(n, s);
        vector<vector<string>> ans;
        place(0, leftrow, upperleftdiagonal, lowerleftdiagonal, board, ans, n);
        return ans;
    }
};