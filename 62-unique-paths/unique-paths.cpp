class Solution {
public:

    int memo[101][101];

    int dfs(int m, int n, int row, int col) {
        // If out of bounds or already visited, return 0
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return 0;
        }

        
        // If we reach the bottom-right corner, return 1
        if (row == m - 1 && col == n - 1) {
            return 1;
        }

        if(memo[row][col]!= -1){
            return memo[row][col];
        }

        // Move right and down
        int right = dfs(m, n, row, col + 1);
        int down = dfs(m, n, row + 1, col);

        // Sum the results of moving right and down
        return memo[row][col]= right + down;
    }

    int uniquePaths(int m, int n) {
        memset(memo,-1,sizeof(memo));
        return dfs(m, n, 0, 0);
    }
};
