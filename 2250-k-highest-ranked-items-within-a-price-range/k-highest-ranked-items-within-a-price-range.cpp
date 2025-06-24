class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing,
                                            vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<tuple<int, int, int>> q; // {row, col, distance}
        q.push({start[0], start[1], 0});
        vis[start[0]][start[1]] = true;

        vector<vector<int>> result;
        vector<tuple<int, int, int, int>> candidates; // {dist, price, row, col}

        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            auto [r, c, dist] = q.front(); q.pop();

            int price = grid[r][c];
            if (price >= pricing[0] && price <= pricing[1])
                candidates.emplace_back(dist, price, r, c);

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    !vis[nr][nc] && grid[nr][nc] != 0) {
                    vis[nr][nc] = true;
                    q.push({nr, nc, dist + 1});
                }
            }
        }

        sort(candidates.begin(), candidates.end());

        for (int i = 0; i < min(k, (int)candidates.size()); ++i) {
            auto [dist, price, r, c] = candidates[i];
            result.push_back({r, c});
        }

        return result;
    }
};
