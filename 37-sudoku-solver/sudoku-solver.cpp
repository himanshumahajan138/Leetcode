const static auto initialize = [] {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:

    bool is_valid(int row,int col,char&c,vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(board[row][i]==c)return false;//if same char found in row 
            if(board[i][col]==c)return false;//if same char found in col
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;//found in 3x3 part
        }//above formula is very very important to understand
        return true;
    }

    bool solve(vector<vector<char>>&board){
        int n = board.size();
        for(int row=0 ; row<n ; row++){//for traversing in rows 
            for(int col=0;col<n;col++){//for traversing in columns
                if(board[row][col]=='.'){//if there is some empty place in board 
                    for(char c='1';c<='9';c++){//check all values of char '1' to '9' 
                        if(is_valid(row,col,c,board)){//if for any value its valid 
                            board[row][col]=c;//take condition change the board value
                            if(solve(board))return true;//again check for next blank
                            else board[row][col]='.';//if unable to solve so backtrack
                        }
                    }
                    return false;//not solved for any value of char '1' to '9'
                }
            }
        }
        return true;//if there is no blank left in board then means its solved so true
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};