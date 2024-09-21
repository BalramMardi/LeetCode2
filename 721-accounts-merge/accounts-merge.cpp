class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i) {
                parent[i] = i; // Initially, each element is its own parent
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                // Union by rank
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>> accounts) {
        int n = accounts.size();
        DSU dsu(n);

        // Map each email to the account index it belongs to
        unordered_map<string, int> emailToIndex;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToIndex.count(email)) {
                    // If email is already associated with another account,
                    // union them
                    dsu.unite(i, emailToIndex[email]);
                } else {
                    emailToIndex[email] = i;
                }
            }
        }

        // Map from root account index to all emails that belong to the same
        // person
        unordered_map<int, vector<string>> indexToEmails;

        for (const auto& [email, index] : emailToIndex) {
            int root = dsu.find(index);
            indexToEmails[root].push_back(email);
        }

        // Prepare the result
        vector<vector<string>> mergedAccounts;

        for (const auto& [index, emails] : indexToEmails) {
            vector<string> account;
            account.push_back(accounts[index][0]); // Account name
            account.insert(account.end(), emails.begin(), emails.end());
            sort(account.begin() + 1,
                 account.end()); // Sort emails lexicographically
            mergedAccounts.push_back(account);
        }

        return mergedAccounts;
    }
};