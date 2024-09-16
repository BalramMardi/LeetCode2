class Solution {
public:
    long long mod = 1e9 + 7;
    
    long long countWays(int n, std::vector<long long>& dp) {
        if (n == 0) return 1;  // Base case: 1 way for no pickup and delivery
        if (dp[n] != -1) return dp[n];  // Return if already computed
        
        // Recursive formula: f(n) = (2n-1) * n * f(n-1)
        long long ways = (countWays(n-1, dp) * (2 * n - 1) % mod * n % mod) % mod;
        return dp[n] = ways;  // Store the result in dp array
    }
    
    int countOrders(int n) {
        std::vector<long long> dp(n + 1, -1);  // Initialize memoization table
        return countWays(n, dp);  // Start solving from n pairs
    }
};



/* class Solution {
public:
    int MOD = 1e9+7;
    int countOrders(int n) {
        if(n==1){
            return 1;
        }
        long long result = 1;
        for(int i=2;i<=n;i++){

            int spaces = 2*(i-1)+1;
            int poss = (spaces * (spaces+1))/2;

            result *= poss;

            result %= MOD;
            
        }

        return result;
    }
}; */