class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int& ans, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) 
            return grid[i][j]; 
        
        if (dp[i][j] != INT_MAX) 
            return dp[i][j];
        
        int mn = INT_MAX;
        if (i > 0) 
            mn = min(mn, helper(grid, i - 1, j, ans, dp)); 
        if (j > 0) 
            mn = min(mn, helper(grid, i, j - 1, ans, dp)); 
        ans = max(ans, grid[i][j] - mn); 
        return dp[i][j] = min(grid[i][j], mn); 
    }

    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX)); 
        helper(grid, m - 1, n - 1, ans, dp);
        return ans;
    }
};




/* class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int mn = INT_MAX;
                if (i == 0 && j == 0)
                    continue;
                if (i != 0)
                    mn = min(mn, grid[i - 1][j]);
                if (j != 0)
                    mn = min(mn, grid[i][j - 1]);
                ans = max(ans, grid[i][j] - mn);
                grid[i][j] = min(grid[i][j], mn);
            }
        }
        return ans;
    }
}; */