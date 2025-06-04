#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int n) {

        if (n == 0) {
            return 0;
        }

        if (n < 0) {
            return INT_MAX;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int res = INT_MAX;

        for (int i = 1; i * i <= n; i++) {
            int sub = solve(n - i * i);

            if (sub != INT_MAX)
                res = min(res, sub + 1);
        }

        return dp[n] = res;
    }
    int numSquares(int n) {

        dp.resize(n + 1, -1);

        return solve(n);
    }
};

/* class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n+1);

        dp[0]=0;
        dp[1]=1;

        for(int i=2; i<=n ; i++){
                int minn = INT_MAX;
            for(int j=1 ; j*j<= i ; j++){

                int rem = i-j*j;

                if(dp[rem] < minn){
                    minn = dp[rem];
                }
            }

            dp[i] = minn+1;
        }

        return dp[n];

    }
}; */