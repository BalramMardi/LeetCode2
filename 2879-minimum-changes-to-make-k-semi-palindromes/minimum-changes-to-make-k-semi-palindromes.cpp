class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> divs(n + 1);
        for (int d = 1; d < n; ++d) {
            for (int m = d * 2; m <= n; m += d) {
                divs[m].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                for (int d : divs[len]) {
                    int changes = 0;
                    for (int offset = 0; offset < d; ++offset) {
                        int left = i + offset;
                        int right = i + len - d + offset;
                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 1e9));
        for (int i = 0; i < n; ++i) {
            dp[i][1] = cost[i][n - 1];
        }

        for (int p = 2; p <= k; ++p) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n - 1; ++j) {
                    if (cost[i][j] != 1e9 && dp[j + 1][p - 1] != 1e9) {
                        dp[i][p] = min(dp[i][p], cost[i][j] + dp[j + 1][p - 1]);
                    }
                }
            }
        }

        return dp[0][k];
    }
};