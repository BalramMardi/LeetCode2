class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        stack<int> st;
        st.push(0);
        vis[0] = 1;

        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : rooms[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    st.push(v);
                }
            }
        }

        for (int x : vis) if (!x) return false;
        return true;
    }
};