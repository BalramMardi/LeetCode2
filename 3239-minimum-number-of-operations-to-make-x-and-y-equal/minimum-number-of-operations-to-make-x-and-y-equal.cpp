class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x) return y - x;

        queue<pair<int, int>> q;
        q.push({x, 0});
        
        vector<bool> visited(20005, false);
        visited[x] = true;

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            
            int val = current.first;
            int dist = current.second;

            if (val == y) return dist;

            if (val % 11 == 0) {
                int nextVal = val / 11;
                if (!visited[nextVal]) {
                    visited[nextVal] = true;
                    q.push({nextVal, dist + 1});
                }
            }

            if (val % 5 == 0) {
                int nextVal = val / 5;
                if (!visited[nextVal]) {
                    visited[nextVal] = true;
                    q.push({nextVal, dist + 1});
                }
            }

            if (val + 1 < 20000) {
                if (!visited[val + 1]) {
                    visited[val + 1] = true;
                    q.push({val + 1, dist + 1});
                }
            }

            if (val - 1 >= 0) {
                if (!visited[val - 1]) {
                    visited[val - 1] = true;
                    q.push({val - 1, dist + 1});
                }
            }
        }
        return -1;
    }
};