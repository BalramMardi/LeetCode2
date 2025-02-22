#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        if (g[0][0] != 0 || g[n - 1][n - 1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        pq.push({1, {0, 0}}); // {distance, {i, j}}
        dist[0][0] = 1;

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            auto [i, j] = cell;
            pq.pop();

            if (i == n - 1 && j == n - 1) return d;

            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;

                if (ni >= 0 && ni < n && nj >= 0 && nj < n && g[ni][nj] == 0 && d + 1 < dist[ni][nj]) {
                    dist[ni][nj] = d + 1;
                    pq.push({d + 1, {ni, nj}});
                }
            }
        }

        return -1;
    }
};



/* class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& g, vector<vector<bool>>& vis) {
        return i >= 0 && i < n && j >= 0 && j < m && g[i][j] == 0 && !vis[i][j];
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        if (g[0][0] != 0 || g[n - 1][n - 1] != 0) return -1;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        q.push({0, 0});
        vis[0][0] = true;
        int res = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                if (i == n - 1 && j == n - 1) return res;

                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (isValid(ni, nj, n, n, g, vis)) {
                        q.push({ni, nj});
                        vis[ni][nj] = true;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
 */