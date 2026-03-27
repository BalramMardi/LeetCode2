class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];

        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            int time = pq.top().first; 
            int node = pq.top().second; 
            pq.pop();

         
            for(auto it : adj[node]){
                int neighbourNode = it.first; 
                int wt = it.second; 

            
                if(wt + dist[node] < dist[neighbourNode]){
                    dist[neighbourNode] = wt + dist[node];
                    pq.push({dist[neighbourNode] , neighbourNode });
                }
            }  
        }

    
        int mx = *max_element(dist.begin()+1 , dist.end() );
        return mx == INT_MAX ? -1 : mx;
    }
};