const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool find_next(int row, int col, int i, int m, int n,
                   vector<vector<char>>& board, string word) {

        if (i == word.length())
            return true;

        if (row < 0 || col < 0 || row == m || col == n ||
            word[i] != board[row][col] || board[row][col] == '!')
            return false;

        char current = board[row][col];
        board[row][col] = '!';

        bool top = find_next(row - 1, col, i + 1, m, n, board, word);
        bool bottom = find_next(row + 1, col, i + 1, m, n, board, word);
        bool right = find_next(row, col + 1, i + 1, m, n, board, word);
        bool left = find_next(row, col - 1, i + 1, m, n, board, word);

        board[row][col]=current;

        return top || bottom || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == word[0]) {
                    if (find_next(row, col, 0, m, n, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};