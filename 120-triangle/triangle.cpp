class Solution {
public:
    int minimumTotalRecursive(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& memo) {
        // Base case: if we reach the last row, return the value at that position
        if (row == triangle.size() - 1) {
            return triangle[row][col];
        }
        
        // If the value is already computed, return it from the memo table
        if (memo[row][col] != INT_MAX) {
            return memo[row][col];
        }

        // Recursively find the minimum path sum by going down to the next row
        int left = minimumTotalRecursive(triangle, row + 1, col, memo);
        int right = minimumTotalRecursive(triangle, row + 1, col + 1, memo);

        // Calculate the minimum path sum for the current position and store it in the memo table
        memo[row][col] = triangle[row][col] + min(left, right);

        // Return the computed value
        return memo[row][col];
    }

      int minimumTotal(vector<vector<int>>& triangle) {
        // Create a memoization table initialized with a special value (e.g., INT_MAX)
        vector<vector<int>> memo(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        // Start the recursion from the top of the triangle
        return minimumTotalRecursive(triangle, 0, 0, memo);
    }
};