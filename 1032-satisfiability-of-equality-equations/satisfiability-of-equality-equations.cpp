class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU() {
            parent.resize(26);
            for (int i = 0; i < 26; i++) {
                parent[i] = i;
            }
            rank.assign(26, 0);
        }

        int find(int x) {
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int parentX = find(x);
            int parentY = find(y);

            if (parentX != parentY) {
                if (rank[parentX] < rank[parentY]) {
                    parent[parentX] = parentY;
                } else if (rank[parentX] > rank[parentY]) {
                    parent[parentY] = parentX;
                } else {
                    parent[parentY] = parentX;
                    rank[parentX]++;
                }
            }
        }
    };

    bool equationsPossible(vector<string>& equations) {
        DSU dsu;

        vector<string> equal, notEqual;

        for (string st : equations) {
            if (st[1] == '!') {
                notEqual.push_back(st);
            } else {
                equal.push_back(st);
            }
        }

        for (string st : equal) {
            int first = st[0] - 'a';
            int last = st[3] - 'a';
            dsu.unite(first, last);
        }

        for (string st : notEqual) {
            int first = dsu.find(st[0] - 'a');
            int last = dsu.find(st[3] - 'a');
            if (first == last) {
                return false;
            }
        }

        return true;
    }
};
