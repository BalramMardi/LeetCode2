class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int day = 0;
        int i = 0;       
        int eaten = 0;

        while (i < n || !pq.empty()) {
            if (i < n && apples[i] > 0 && days[i] > 0) {
                int expiry = i + days[i]; 
                pq.push({expiry, apples[i]});
            }

            while (!pq.empty() && pq.top().first <= day) pq.pop();

            if (!pq.empty()) {
                auto cur = pq.top(); pq.pop();
                
                cur.second -= 1;
                eaten += 1;
                if (cur.second > 0) {
                    pq.push(cur);
                }
            }

            day += 1;
            i += (i < n ? 1 : 0); 
        }

        return eaten;
    }
};