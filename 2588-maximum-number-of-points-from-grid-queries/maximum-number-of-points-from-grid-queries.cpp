class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(queries.size(), 0);
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        vector<pair<int, int>> sorted_queries;
        for (int i = 0; i < queries.size(); i++) {
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        int count = 0, maxValue = 0;
        int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        for (auto &[q, index] : sorted_queries) {
            while (!pq.empty() && pq.top().first < q) {
                auto [val, pos] = pq.top(); pq.pop();
                int x = pos.first, y = pos.second;
                count++;

                for (int d = 0; d < 4; d++) {
                    int new_x = x + dir[d][0], new_y = y + dir[d][1];
                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !vis[new_x][new_y]) {
                        pq.push({grid[new_x][new_y], {new_x, new_y}});
                        vis[new_x][new_y] = true;
                    }
                }
            }
            ans[index] = count;
        }

        return ans;
    }
};



/* class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        vector<int> ans(queries.size(), 0); 

        for(int i = 0; i < queries.size(); i++) {
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int score = 0;
            queue<pair<int, int>> q;

            
            if (!vis[0][0] && grid[0][0] < queries[i]) {
                q.push({0, 0});
                vis[0][0] = true;
            }

            while (!q.empty()) {
                int x_curr = q.front().first;
                int y_curr = q.front().second;
                q.pop();

                score++;

                for (int d = 0; d < 4; d++) {
                    int new_x = x_curr + dir[d][0];
                    int new_y = y_curr + dir[d][1];

                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !vis[new_x][new_y] && grid[new_x][new_y] < queries[i]) {
                        q.push({new_x, new_y});
                        vis[new_x][new_y] = true;
                    }
                }
            }

            ans[i] = score;
        }

        return ans;
    }
}; */