class Solution {
public:
    int dp[55][6];

    int solve(int n, int idx) {
        if (n == 0) return 1;          
        if (idx == 5) return 0;        
        if (dp[n][idx] != -1) return dp[n][idx];

        int take = solve(n - 1, idx);   
        int skip = solve(n, idx + 1);

        return dp[n][idx] = take + skip;
    }

    int countVowelStrings(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0);
    }
};

/* class Solution {
public:
    int countVowelStrings(int n) {
        long long res = 1;
        
        for (int i = 1; i <= 4; ++i) {
            res = res * (n + 5 - i) / i;
        }
        return (int)res;
    }
}; */