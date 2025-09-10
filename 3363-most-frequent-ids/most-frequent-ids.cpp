class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
            int n = nums.size();
            vector<long long> ans(n);

            unordered_map<long long, long long> count; 
            priority_queue<pair<long long, long long>> pq;

            for (int i = 0; i < n; i++) {
                long long id = nums[i];
                long long change = freq[i];

                count[id] += change;
                if (count[id] < 0) count[id] = 0; 

                pq.push({count[id], id});

                while (!pq.empty() && pq.top().first != count[pq.top().second]) {
                    pq.pop();
                }

                ans[i] = pq.empty() ? 0 : pq.top().first;
            }

            return ans;
    }
};