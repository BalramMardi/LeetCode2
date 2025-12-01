class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        long long extra = 0;
        int m = batteries.size();

        for (int i = 0; i < m - n; i++) {
            extra += batteries[i];
        }

        vector<long long> live;
        for (int i = m - n; i < m; i++) {
            live.push_back(batteries[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            long long need = 1LL * (i + 1) * (live[i + 1] - live[i]);
            if (extra < need) {
                return live[i] + extra / (i + 1);
            }
            extra -= need;
        }

        return live[n - 1] + extra / n;
    }
};