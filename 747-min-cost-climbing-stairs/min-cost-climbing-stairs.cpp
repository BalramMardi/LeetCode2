class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& cost, int idx) {

        if (idx < 0) {
            return 0;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        if (idx == 0) {
            return cost[0];
        }
        if (idx == 1) {
            return cost[1];
        }  

        int res = cost[idx] + min(solve(cost, idx - 1), solve(cost, idx - 2));

        return dp[idx] = res;
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n+1,-1);
        return min(solve(cost, n - 1), solve(cost, n - 2));
    }

    /* int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int first = cost[0];
        int second = cost[1];
        if(n<=2){
            return min(first,second);
        }
        for(int i=2;i<n;i++){
            int curr = cost[i]+min(first,second);
            first=second;
            second=curr;
        }

        return min(first,second);

    } */
};