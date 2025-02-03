class Solution {
public:
    typedef pair<int, int> pp;
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> queryWithIndex;
        for (int i = 0; i < queries.size(); i++) {
            queryWithIndex.push_back({queries[i], i});
        }

        sort(queryWithIndex.begin(), queryWithIndex.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        vector<int> result(queries.size(), -1);
        int i = 0, n = intervals.size();

        for (auto [q, idx] : queryWithIndex) {
            while (i < n && intervals[i][0] <= q) {
                int length = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({length, intervals[i][1]});
                i++;
            }

            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                result[idx] = minHeap.top().first;
            }
        }

        return result;
    }
};