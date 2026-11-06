class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<pair<int, int>> sq(q);
        for (int i = 0; i < q; ++i) {
            sq[i] = {queries[i], i};
        }
        sort(sq.begin(), sq.end());

        vector<int> ans(q);
        unordered_map<int, int> counts;
        int left = 0, right = 0;
        int m = logs.size();

        for (int i = 0; i < q; ++i) {
            int q_time = sq[i].first;
            int idx = sq[i].second;
            int start_time = q_time - x;

            while (right < m && logs[right][1] <= q_time) {
                counts[logs[right][0]]++;
                right++;
            }

            while (left < m && logs[left][1] < start_time) {
                counts[logs[left][0]]--;
                if (counts[logs[left][0]] == 0) {
                    counts.erase(logs[left][0]);
                }
                left++;
            }

            ans[idx] = n - counts.size();
        }

        return ans;
    }
};