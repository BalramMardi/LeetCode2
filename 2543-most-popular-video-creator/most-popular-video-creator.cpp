class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string, long long> totalViews;
        unordered_map<string, pair<long long, string>> bestVideo; 

        for (int i = 0; i < n; ++i) {
            const string &c = creators[i];
            const string &id = ids[i];
            long long v = views[i];
            totalViews[c] += v;

            auto it = bestVideo.find(c);
            if (it == bestVideo.end()) {
                bestVideo[c] = {v, id};
            } else {
                long long curV = it->second.first;
                string curId = it->second.second;
                if (v > curV || (v == curV && id < curId)) {
                    bestVideo[c] = {v, id};
                }
            }
        }

        long long maxTotal = 0;
        for (auto &p : totalViews) maxTotal = max(maxTotal, p.second);

        vector<vector<string>> ans;
        for (auto &p : totalViews) {
            if (p.second == maxTotal) {
                const string &creator = p.first;
                const string &chosenId = bestVideo[creator].second;
                ans.push_back({creator, chosenId});
            }
        }
        return ans;
    }
};
