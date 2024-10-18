#include <vector>
#include <algorithm>
using namespace std;

void dfs(int u, vector<int>& memo, vector<int>& edges) {
    int time = 0;
    while (u != -1 && memo[u] == -1) {
        memo[u] = time++;
        u = edges[u];
    }
}

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> m1(n, -1), m2(n, -1);

        dfs(node1, m1, edges);
        dfs(node2, m2, edges);

        int id = -1, minMax = 1e9;
        for (int i = 0; i < n; i++) {
            if (min(m1[i], m2[i]) != -1 && max(m1[i], m2[i]) < minMax) {
                minMax = max(m1[i], m2[i]);
                id = i;
            }
        }
        return id;
    }
};
