class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n);

       
        for (auto& edge : redEdges) {
            graph[edge[0]].emplace_back(edge[1], 0);
        }

        for (auto& edge : blueEdges) {
            graph[edge[0]].emplace_back(edge[1], 1);
        }
   
        vector<int> result(n, -1);
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(2, false));

        q.push({0, 0, 0}); 
        q.push({0, 1, 0}); 
        visited[0][0] = visited[0][1] = true;
        result[0] = 0;

        while (!q.empty()) {
            auto [node, color, dist] = q.front();
            q.pop();

            
            for (auto& [neighbor, nextColor] : graph[node]) {
                if (color != nextColor &&
                    !visited[neighbor][nextColor]) { 
                    visited[neighbor][nextColor] = true;
                    q.push({neighbor, nextColor, dist + 1});

                    if (result[neighbor] == -1) {
                        result[neighbor] = dist + 1;
                    }
                }
            }
        }

        return result;
    }
};

/*
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges,
vector<vector<int>>& blue_edges){

        vector<int> res(n, -1), v1(n, 0), v2(n, 0);
        vector<vector<pair<int, int>>> vp(n);
        queue<pair<int, int>> q;

        for(auto &it : red_edges) vp[it[0]].push_back({it[1], 1});
        for(auto &it : blue_edges) vp[it[0]].push_back({it[1], 2});

        res[0] = 0;
        v1[0] = 1;
        v2[0] = 1;
        int temp = 1;

        for(auto &it : vp[0])
        {
            q.push(it);
            if(res[it.first] == -1) res[it.first] = temp;
        }

        while(!q.empty())
        {
            int len = q.size();
            temp++;
            for(int i=0; i<len; ++i)
            {
                auto val = q.front();
                q.pop();
                if(val.second == 1) v1[val.first] = 1;
                else v2[val.first] = 1;

                for(auto &it : vp[val.first])
                {
                    if(val.second == 1 && (v2[it.first] || it.second==1))
continue; if(val.second == 2 && (v1[it.first] || it.second==2)) continue;
                    q.push(it);
                    if(res[it.first] == -1) res[it.first] = temp;
                }
            }
        }
        return res;
    }
};
 */