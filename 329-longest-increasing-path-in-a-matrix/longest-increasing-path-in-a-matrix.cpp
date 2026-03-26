class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] > 0) return memo[i][j];
        
        int max_len = 1;
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
                max_len = max(max_len, 1 + dfs(matrix, x, y, memo));
            }
        }
        
        memo[i][j] = max_len;
        return max_len;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int longest_path = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longest_path = max(longest_path, dfs(matrix, i, j, memo));
            }
        }
        
        return longest_path;
    }
};