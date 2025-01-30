class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> seen;

        pq.push(1);
        seen.insert(1);

        long long currentUgly = 1;
        vector<int> factors = {2, 3, 5};

        for (int i = 1; i <= n; i++) {
            currentUgly = pq.top();
            pq.pop();

            for (int factor : factors) {
                long long nextUgly = currentUgly * factor;
                if (seen.find(nextUgly) == seen.end()) {
                    pq.push(nextUgly);
                    seen.insert(nextUgly);
                }
            }
        }
        return (int)currentUgly;
    }
};