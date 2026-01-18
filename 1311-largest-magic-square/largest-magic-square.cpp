
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> rowSum(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> colSum(m + 1, vector<long long>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }

        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i <= m - k; ++i) {
                for (int j = 0; j <= n - k; ++j) {
                    long long target = rowSum[i][j + k] - rowSum[i][j];
                    bool ok = true;

                    for (int r = 1; r < k; ++r) {
                        if (rowSum[i + r][j + k] - rowSum[i + r][j] != target) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    for (int c = 0; c < k; ++c) {
                        if (colSum[i + k][j + c] - colSum[i][j + c] != target) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;

                    long long d1 = 0, d2 = 0;
                    for (int d = 0; d < k; ++d) {
                        d1 += grid[i + d][j + d];
                        d2 += grid[i + d][j + k - 1 - d];
                    }
                    if (d1 != target || d2 != target) ok = false;

                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};