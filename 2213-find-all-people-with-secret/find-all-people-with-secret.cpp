class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

            vector<vector<pair<int,int>>> graph(n);

    for (auto &meetings : meetings) {
        int x = meetings[0], y = meetings[1], t = meetings[2];
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }

    vector<int> earliest(n, INT_MAX);
    queue<pair<int,int>> q;

    q.push({0, 0});
    earliest[0] = 0;
    q.push({0, firstPerson});
    earliest[firstPerson] = 0;

    while (!q.empty()) {
        auto [time, person] = q.front();
        q.pop();

        if (time > earliest[person]) continue;

        for (auto &[nextPerson, meetTime] : graph[person]) {
            if (time <= meetTime && earliest[nextPerson] > meetTime) {
                earliest[nextPerson] = meetTime;
                q.push({meetTime, nextPerson});
            }
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
        if (earliest[i] != INT_MAX)
            ans.push_back(i);

    return ans;
}
};