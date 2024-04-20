class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Initialize vectors to keep track of numbers seen in each row, column, and subgrid
        vector<vector<bool>> row(9, vector<bool>(9, false)); // 9x9 vector to track numbers in each row
        vector<vector<bool>> col(9, vector<bool>(9, false)); // 9x9 vector to track numbers in each column
        vector<vector<bool>> sub(9, vector<bool>(9, false)); // 9x9 vector to track numbers in each 3x3 subgrid

        // Traverse the Sudoku board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue; // Skip if the cell is empty

                // Convert the character to integer and subtract 1 to get the corresponding index (0-based)
                int num = c - '0' - 1;

                // Calculate the index of the subgrid
                int k = i / 3 * 3 + j / 3;

                // Check if the current number is already seen in the same row, column, or subgrid
                if (row[i][num] || col[j][num] || sub[k][num]) {
                    return false; // If already seen, the Sudoku board is invalid
                }

                // Mark the current number as seen in the corresponding row, column, and subgrid
                row[i][num] = true;
                col[j][num] = true;
                sub[k][num] = true;
            }
        }

        // If all numbers satisfy the Sudoku constraints, the Sudoku board is valid
        return true;
    }
};
