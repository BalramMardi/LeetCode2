class Solution {
public:

    bool isQueenSafe(vector<vector<bool>> &chess, int row, int col) {
        // Check the column
        for (int i = row - 1; i >= 0; i--) {
            if (chess[i][col] == true) {
                return false;
            }
        }

        // Check the upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] == true) {
                return false;
            }
        }

        // Check the upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < chess[0].size(); i--, j++) {
            if (chess[i][j] == true) {
                return false;
            }
        }

        return true;
    }

    void nQueen(vector<vector<bool>> &chess, vector<vector<int>> &ans, vector<int> &path, int row) {
        if (row == chess.size()) {
            ans.push_back(path);
            return;
        }

        for (int col = 0; col < chess[0].size(); col++) {
            if (isQueenSafe(chess, row, col)) {
                chess[row][col] = true;
                path.push_back(col);
                nQueen(chess, ans, path, row + 1);
                path.pop_back();
                chess[row][col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> chess(n, vector<bool>(n, false));
        vector<vector<int>> ans;
        vector<int> path;
        vector<vector<string>> result;

        nQueen(chess, ans, path, 0);

        for (auto &solution : ans) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < solution.size(); i++) {
                board[i][solution[i]] = 'Q';
            }
            result.push_back(board);
        }

        return result;
    }
};
