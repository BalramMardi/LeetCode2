class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char val) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[row][j] == val) {
                return false;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == val) {
                return false;
            }
        }

        int smRow = (row / 3) * 3;
        int smCol = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[smRow + i][smCol + j] == val) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Sudoku(vector<vector<char>>& board, int row, int col) {
        if (row == board.size()) {
            return true;
        }

        int newRow = 0;
        int newCol = 0;

        if (col == board[0].size() - 1) {
            newRow = row + 1;
            newCol = 0;
        } else {
            newRow = row;
            newCol = col + 1;
        }

        if (board[row][col] != '.') {
            if (Sudoku(board, newRow, newCol)) {
                return true;
            }
        } else {
            for (char po = '1'; po <= '9'; po++) {
                if (isValid(board, row, col, po)) {
                    board[row][col] = po;
                    if (Sudoku(board, newRow, newCol)) {
                        return true;
                    }
                    board[row][col] = '.';
                }
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { Sudoku(board, 0, 0); }
};