class Solution {
public:
    int n;
    vector<int> prefix;
    vector<vector<int>> dp;

    int dfs(int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int removeLeft = prefix[j + 1] - prefix[i + 1] - dfs(i + 1, j);
        int removeRight = prefix[j] - prefix[i] - dfs(i, j - 1);

        return dp[i][j] = max(removeLeft, removeRight);
    }

    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        prefix.resize(n + 1);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + stones[i];

        dp.assign(n, vector<int>(n, -1));
        return dfs(0, n - 1);
    }
};