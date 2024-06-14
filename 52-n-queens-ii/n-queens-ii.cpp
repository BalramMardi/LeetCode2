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

    void nQueen(vector<vector<bool>> &chess, int &ans, int row) {
        if (row == chess.size()) {
            ans++;
            return;
        }

        for (int col = 0; col < chess[0].size(); col++) {
            if (isQueenSafe(chess, row, col)) {
                chess[row][col] = true;
                nQueen(chess, ans, row + 1);
                chess[row][col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<bool>> chess(n, vector<bool>(n, false));
        int ans=0;

        nQueen(chess, ans, 0);

        

        return ans;
    }
};




