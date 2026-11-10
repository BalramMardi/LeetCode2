class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> memo(n, -1);
        return solve(0, n, costs, memo);
    }

    int solve(int i, int n, vector<int>& costs, vector<int>& memo) {
        if (i == n) {
            return 0;
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int min_cost = INT_MAX / 2;
        
        for (int j = i + 1; j <= min(i + 3, n); ++j) {
            int jump_cost = costs[j - 1] + (j - i) * (j - i);
            min_cost = min(min_cost, jump_cost + solve(j, n, costs, memo));
        }
        
        return memo[i] = min_cost;
    }
};