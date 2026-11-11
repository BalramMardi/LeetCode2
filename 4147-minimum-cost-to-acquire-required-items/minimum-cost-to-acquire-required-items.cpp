class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        long long min_need = min(need1, need2);
        long long cost_min = min_need * costBoth + 1LL * (need1 - min_need) * cost1 + 1LL * (need2 - min_need) * cost2;
        ans = min(ans, cost_min);
        
        long long max_need = max(need1, need2);
        long long cost_max = max_need * costBoth;
        ans = min(ans, cost_max);
        
        return ans;
    }
};