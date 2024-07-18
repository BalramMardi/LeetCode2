class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> moves = {
            {4, 6},    
            {6, 8},    
            {7, 9},    
            {4, 8},   
            {3, 9, 0},
            {},       
            {1, 7, 0},
            {2, 6},   
            {1, 3},   
            {2, 4}    
        };
        
        const int MOD = 1e9 + 7;
        
        vector<vector<int>> dp(n, vector<int>(10, 0));
        
        // Initialize base cases
        for (int i = 0; i < 10; ++i) {
            dp[0][i] = 1;
        }
        
        // Fill the DP table
        for (int step = 1; step < n; ++step) {
            for (int i = 0; i < 10; ++i) {
                dp[step][i] = 0;
                for (int move : moves[i]) {
                    dp[step][i] = (dp[step][i] + dp[step - 1][move]) % MOD;
                }
            }
        }
        
        // Sum up all numbers of length n
        int result = 0;
        for (int i = 0; i < 10; ++i) {
            result = (result + dp[n - 1][i]) % MOD;
        }
        
        return result;
    }
};
