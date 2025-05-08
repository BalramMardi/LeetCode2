class Solution {
public:
    struct Cell {
        int row, col, time;
        Cell(int r, int c, int t) : row(r), col(c), time(t) {}
        bool operator>(const Cell& other) const {
            return time > other.time;
        }
    };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        minTime[0][0] = 0;
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();

            if (visited[cur.row][cur.col]) continue;
            visited[cur.row][cur.col] = true;

            for (auto& dir : directions) {
                int newRow = cur.row + dir[0];
                int newCol = cur.col + dir[1];

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) continue;

                int newTime = max(minTime[cur.row][cur.col], moveTime[newRow][newCol]) + (cur.row + cur.col) % 2 + 1 ;
                if (newTime < minTime[newRow][newCol]) {
                    minTime[newRow][newCol] = newTime;
                    pq.emplace(newRow, newCol, newTime);
                }
            }
        }

        return minTime[n - 1][m - 1];
    }
};
