class Solution {
public:
        bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto &t : trips)
            m[t[1]] += t[0], m[t[2]] -= t[0];
        for (auto &v : m)
            if ((capacity -= v.second) < 0)
                return false;
        return true;
    }
};


/* class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> events;

        for (auto& trip : trips) {
            events.push_back({trip[1], trip[0]}); 
            events.push_back({trip[2], -trip[0]});
        }

        sort(events.begin(), events.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int currentPassengers = 0;
        
        for (auto& event : events) {
            currentPassengers += event.second;
            if (currentPassengers > capacity) return false;
        }

        return true;
    }
}; */



/* class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<trips.size();i++){
            pq.push(make_pair(trips[i][1],trips[i][0]));
            pq.push(make_pair(trips[i][2],-trips[i][0]));
        }
        int ans = 0;
        while(!pq.empty()){
            pair<int,int> a = pq.top();
            pq.pop();
            ans+=a.second;
            if(ans>capacity) return false;
        }
        return true;
    }
}; */