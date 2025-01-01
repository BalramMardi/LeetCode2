class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int rows = seats.size();
        int cols = seats[0].size();
        int maxState = (1 << cols);

        vector<vector<int>> dp(rows, vector<int>(maxState, -1));

        auto isValid = [&](int state, int row) {
            for (int j = 0; j < cols; ++j) {
                if ((state & (1 << j)) && seats[row][j] == '#')
                    return false;
                if ((state & (1 << j)) && j > 0 && (state & (1 << (j - 1))))
                    return false;
            }
            return true;
        };

        auto isCompatible = [&](int prevState, int currState) {
            for (int j = 0; j < cols; ++j) {
                if ((currState & (1 << j)) &&
                    ((j > 0 && (prevState & (1 << (j - 1)))) ||
                     (j < cols - 1 && (prevState & (1 << (j + 1)))))) {
                    return false;
                }
            }
            return true;
        };

        auto countBits = [&](int state) { return __builtin_popcount(state); };

        for (int state = 0; state < maxState; ++state) {
            if (isValid(state, 0)) {
                dp[0][state] = countBits(state);
            }
        }

        for (int i = 1; i < rows; ++i) {
            for (int prevState = 0; prevState < maxState; ++prevState) {
                if (dp[i - 1][prevState] == -1)
                    continue;
                for (int currState = 0; currState < maxState; ++currState) {
                    if (isValid(currState, i) &&
                        isCompatible(prevState, currState)) {
                        dp[i][currState] =
                            max(dp[i][currState],
                                dp[i - 1][prevState] + countBits(currState));
                    }
                }
            }
        }

        int result = 0;
        for (int state = 0; state < maxState; ++state) {
            result = max(result, dp[rows - 1][state]);
        }

        return result;
    }
};