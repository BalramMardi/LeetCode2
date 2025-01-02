class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        int fullMask = (1 << m) - 1;

        vector<vector<long long>> dp(n + 1, vector<long long>(1 << m, LLONG_MAX));
        dp[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int mask = 0; mask <= fullMask; ++mask) {
                if (dp[i][mask] == LLONG_MAX) 
                    continue;
                for (int j = 0; j < m; ++j) {
                    int newMask = mask | (1 << j);
                    dp[i + 1][newMask] = min(dp[i + 1][newMask], dp[i][mask] + cost[i][j]);
                }
            }
        }

        long long result = LLONG_MAX;
        for (int mask = 0; mask <= fullMask; ++mask) {
            long long additionalCost = 0;
            for (int j = 0; j < m; ++j) {
                if (!(mask & (1 << j))) {
                    int minCost = INT_MAX;
                    for (int i = 0; i < n; ++i) {
                        minCost = min(minCost, cost[i][j]);
                    }
                    additionalCost += minCost;
                    if (additionalCost >= LLONG_MAX) {
                        additionalCost = LLONG_MAX;  
                        break;
                    }
                }
            }
            if (dp[n][mask] != LLONG_MAX) {  
                result = min(result, dp[n][mask] + additionalCost);
            }
        }

        return result == LLONG_MAX ? -1 : static_cast<int>(result);
    }
};
