class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        priority_queue<int,vector<int>,greater<int>> pq;

        int maxi=0;

        for(int i=0;i<n;i++){
            maxi = max(maxi, events[i][1]);
        }

        sort(events.begin(),events.end());

        int j=0;
        int ans=0;
        for(int i=0;i<=maxi;i++){

            while(j<n && events[j][0] <= i){
                pq.push(events[j][1]);
                j++;
            }

            while(pq.size() && pq.top() < i){
                pq.pop();
            }

            if(pq.size()){
                pq.pop();
                ans++;
            }

        }

        return ans;
    }
};