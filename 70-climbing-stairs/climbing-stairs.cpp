/* class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};
 */


class Solution {
public:
    vector<int> dp;

    int solve(int n){

        if(n < 0){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        if(n==0){
            return 1;
        }

        int res = solve(n-1)+solve(n-2);

        return dp[n] = res;
    }



    int climbStairs(int n) {
        dp.assign(n+1,-1);

        return solve(n);
    }
};