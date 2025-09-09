class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
         unordered_map<int,int> freq;
        for (int b : barcodes) freq[b]++;

        priority_queue<pair<int,int>> pq;
        for (auto &it : freq) pq.push({it.second, it.first});

        vector<int> res;
        while (pq.size() >= 2) {
            auto [cnt1, val1] = pq.top(); pq.pop();
            auto [cnt2, val2] = pq.top(); pq.pop();

            // Place them alternately
            res.push_back(val1);
            res.push_back(val2);

            if (--cnt1 > 0) pq.push({cnt1, val1});
            if (--cnt2 > 0) pq.push({cnt2, val2});
        }

        if (!pq.empty()) res.push_back(pq.top().second);

        return res;
    }
};