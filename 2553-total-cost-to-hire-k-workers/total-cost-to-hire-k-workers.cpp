class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> left, right;

        int i = 0, j = n - 1;
        for (int cnt = 0; cnt < candidates && i <= j; cnt++) left.push({costs[i], i++});
        for (int cnt = 0; cnt < candidates && j >= i; cnt++) right.push({costs[j], j--});

        for (int hire = 0; hire < k; hire++) {
            if (!right.empty() && (left.empty() || right.top() < left.top())) {
                auto [cost, idx] = right.top(); right.pop();
                ans += cost;
                if (j >= i) right.push({costs[j], j--});
            } else {
                auto [cost, idx] = left.top(); left.pop();
                ans += cost;
                if (i <= j) left.push({costs[i], i++});
            }
        }
        return ans;
    }
};