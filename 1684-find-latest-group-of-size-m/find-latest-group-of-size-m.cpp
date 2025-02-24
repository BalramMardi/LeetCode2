class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for (int i = 0; i <= n; ++i)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void merge(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY])
                    swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }

        int getSize(int x) { return size[find(x)]; }
    };

    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n)
            return n;

        DSU dsu(n);
        vector<bool> isSet(n + 1, false);
        int lastStep = -1;

        for (int step = 0; step < n; ++step) {
            int pos = arr[step];
            isSet[pos] = true;

         
            if (pos > 1 && isSet[pos - 1]) {
                if (dsu.getSize(pos - 1) == m)
                    lastStep = step;
                dsu.merge(pos, pos - 1);
            }

            if (pos < n && isSet[pos + 1]) {
                if (dsu.getSize(pos + 1) == m)
                    lastStep = step;
                dsu.merge(pos, pos + 1);
            }

            
            if (dsu.getSize(pos) == m)
                lastStep = step + 1;
        }

        return lastStep;
    }
};