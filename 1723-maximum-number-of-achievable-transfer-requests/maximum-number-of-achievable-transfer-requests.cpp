class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int max_achievable = 0;

        for (int mask = 0; mask < (1 << m); ++mask) {
            vector<int> degree(n, 0);
            int current_requests = 0;

            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    degree[requests[i][0]]--;
                    degree[requests[i][1]]++;
                    current_requests++;
                }
            }

            bool possible = true;
            for (int i = 0; i < n; ++i) {
                if (degree[i] != 0) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                max_achievable = max(max_achievable, current_requests);
            }
        }

        return max_achievable;
    }
};