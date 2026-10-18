class Solution {
    vector<vector<long long>> table;
    long long MOD = 1e9 + 7;

    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if (m < 3) {
            return 1;
        }

        vector<int> leftNodes, rightNodes;
        int root = nums[0];
        for (int i = 1; i < m; ++i) {
            if (nums[i] < root) {
                leftNodes.push_back(nums[i]);
            } else {
                rightNodes.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(leftNodes);
        long long rightWays = dfs(rightNodes);

        return (((table[m - 1][leftNodes.size()] * leftWays) % MOD) * rightWays) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i < n + 1; ++i) {
            table[i][0] = 1;
            table[i][i] = 1;
        }
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};