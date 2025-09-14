class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto &w : words) freq[w]++;

        auto cmp = [&](const pair<string,int>& a, const pair<string,int>& b){
            if(a.second == b.second) return a.first < b.first; 
            return a.second > b.second; 
        };

        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);

        for(auto &p : freq) {
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }

        vector<string> res;
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};