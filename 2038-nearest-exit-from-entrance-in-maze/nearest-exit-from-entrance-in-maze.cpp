class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size(), n = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front(); q.pop();

                if ((x != entrance[0] || y != entrance[1]) && (x == 0 || y == 0 || x == m-1 || y == n-1))
                    return steps;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d], ny = y + dirs[d+1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};