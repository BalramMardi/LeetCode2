/* class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<dp.size();i++){

            for(int j=0;j<i;j++){

                dp[i] += dp[j] * dp[i-j-1];
            }
        }

        return dp[n];
    }
}; */


class Solution {
public:
    int dp[1001];

    int numTrees(int n) {
        
        if (n <= 1) return 1;
        if (dp[n]) return dp[n];
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += numTrees(i - 1) * numTrees(n - i);
        }
        return dp[n] = total;
    }
};