class Solution {
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
};