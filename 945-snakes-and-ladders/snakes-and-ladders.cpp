
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        vector<int> moves(N * N, -1); // Flattened board with snakes and ladders

        // Flatten the 2D board into 1D move array
        bool leftToRight = true;
        int idx = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] != -1) {
                        moves[idx] = board[i][j] - 1; // Convert 1-based to 0-based index
                    }
                    idx++;
                }
            } else {
                for (int j = N - 1; j >= 0; j--) {
                    if (board[i][j] != -1) {
                        moves[idx] = board[i][j] - 1;
                    }
                    idx++;
                }
            }
            leftToRight = !leftToRight;
        }

        // BFS initialization
        vector<bool> visited(N * N, false);
        queue<pair<int, int>> q; // Pair: (current position, number of dice rolls)

        visited[0] = true;
        q.push({0, 0}); // Start at vertex 0 with 0 dice rolls

        while (!q.empty()) {
            pair<int, int> p = q.front();
            int v = p.first;  // Current position
            int dist = p.second; // Current number of dice rolls

            // If we have reached the last cell
            if (v == N * N - 1)
                return dist;

            q.pop();

            // Traverse the next 6 positions (like rolling a dice)
            for (int j = v + 1; j <= (v + 6) && j < N * N; ++j) {
                if (!visited[j]) {
                    visited[j] = true;
                    int nextPos = (moves[j] != -1) ? moves[j] : j; // Move to the destination if snake/ladder exists
                    q.push({nextPos, dist + 1}); // Add the next position with increased distance
                }
            }
        }

        return -1; // If not reachable
    }
};
