class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                            + pre[i - 1][j]
                            + pre[i][j - 1]
                            - pre[i - 1][j - 1];
            }
        }

        auto can = [&](int len) {
            for (int i = 0; i + len <= m; i++) {
                for (int j = 0; j + len <= n; j++) {
                    int sum = pre[i + len][j + len]
                            - pre[i][j + len]
                            - pre[i + len][j]
                            + pre[i][j];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        int l = 0, r = min(m, n), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (can(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};