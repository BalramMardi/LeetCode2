class Solution {
    vector<char> adj[128][128];
    unordered_set<string> failed;

    bool solve(string &curr, string &next)
    {
        if (curr.size() == 1)
            return true;

        if (next.size() == curr.size() - 1) {
            if (failed.count(next))
                return false;
            string empty = "";
            if (solve(next, empty))
                return true;
            failed.insert(next);
            return false;
        }

        int k = next.size();
        char left = curr[k];
        char right = curr[k + 1];

        for (char c : adj[left][right]) {
            next.push_back(c);
            if (solve(curr, next))
                return true;
            next.pop_back();
        }

        return false;
    }

  public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        for (const string &s : allowed) {
            adj[s[0]][s[1]].push_back(s[2]);
        }

        string next = "";
        return solve(bottom, next);
    }
};


/* class Solution {
  public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool build(string row)
    {
        if (row.size() == 1)
            return true;

        if (memo.count(row))
            return memo[row];

        vector<string> nextRows;
        generate(row, 0, "", nextRows);

        for (auto &nxt : nextRows) {
            if (build(nxt))
                return memo[row] = true;
        }

        return memo[row] = false;
    }

    void generate(string &row, int idx, string curr, vector<string> &res)
    {
        if (idx == row.size() - 1) {
            res.push_back(curr);
            return;
        }

        string key = row.substr(idx, 2);
        if (!mp.count(key))
            return;

        for (char c : mp[key]) {
            generate(row, idx + 1, curr + c, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        for (auto &s : allowed) {
            string key = "";
            key += s[0];
            key += s[1];
            mp[key].push_back(s[2]);
        }

        return build(bottom);
    }
}; */