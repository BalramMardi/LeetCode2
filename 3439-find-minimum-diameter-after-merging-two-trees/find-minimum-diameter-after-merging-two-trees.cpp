class Solution {
public:
    int n;
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int source) {
        queue<int> que;
        que.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while(!que.empty()) {
            int size = que.size(); 

            while(size--) {
                int curr = que.front();
                que.pop();

                farthestNode = curr;

                for(auto &nbr : adj[curr]) {
                    if(visited[nbr] == false) {
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }
            if(!que.empty()) {
                distance++;
            }
        }

        return {farthestNode, distance};

    }

    int findDiameter(unordered_map<int, vector<int>> adj) {
        auto [farthestNode, dist] = BFS(adj, 0);
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);
        return diameter;
    }

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1, d2, combined});
        
    }
};

/* class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        int diameter1 =
            findDiameter(adjList1, 0, -1).first;  
        int diameter2 =
            findDiameter(adjList2, 0, -1).first;  


        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };


    pair<int, int> findDiameter(vector<vector<int>>& adjList, int node,
                                int parent) {
        int maxDepth1 = 0,
            maxDepth2 = 0; 
        int diameter = 0;  

        for (int neighbor : adjList[node]) {  
            if (neighbor == parent)
                continue;  

            auto [childDiameter, depth] = findDiameter(adjList, neighbor, node);
            diameter = max(diameter, childDiameter);
            depth++; 
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }

        diameter = max(diameter, maxDepth1 + maxDepth2);

        return {diameter, maxDepth1};
    }
}; */