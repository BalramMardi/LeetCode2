class Solution {
public:
    int maxDiff(vector<int>& piles, int i, int j, vector<vector<int>>& memo) {
    // Base case: if there is only one pile left, the player takes it
    if (i == j) {
        return piles[i];
    }

    // If this subproblem has already been solved, return the result
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Recursive case:
    // Option 1: Take the left pile, then the opponent plays on the remaining subarray (i+1, j)
    // Option 2: Take the right pile, then the opponent plays on the remaining subarray (i, j-1)
    int pickLeft = piles[i] - maxDiff(piles, i + 1, j, memo);
    int pickRight = piles[j] - maxDiff(piles, i, j - 1, memo);

    // Store the result in the memo table and return the best option
    memo[i][j] = max(pickLeft, pickRight);
    return memo[i][j];
}

bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    // Initialize a memo table with -1 (unvisited state)
    vector<vector<int>> memo(n, vector<int>(n, -1));

    // Start the recursive function from the full range (0, n-1)
    return maxDiff(piles, 0, n - 1, memo) > 0;
}
};


/* class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(n));
        
        for(int gap = 0; gap < n; gap++)
            for(int i = 0, j = gap; j < n; i++, j++){
                if(gap == 0) dp[i][j] = piles[i];
                else if(gap == 1) dp[i][j] = max(piles[i], piles[j]);
                else{
                    int case1 = piles[i] + min(dp[i+1][j-1],dp[i+2][j]);
                    int case2 = piles[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    dp[i][j] = max(case1, case2);
                }
            }
        return dp[0][n-1];
    }
}; */