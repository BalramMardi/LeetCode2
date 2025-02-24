class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
    vector<int> getPrimes(int x, vector<int>& spf) {
        vector<int> primes;
        while (x > 1) {
            int p = spf[x];
            primes.push_back(p);
            while (x % p == 0) {
                x /= p;
            }
        }
        return primes;
    }

public:
    bool gcdSort(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> spf(maxVal + 1);
        iota(spf.begin(), spf.end(), 0);

        for (int i = 2; i * i <= maxVal; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        DSU dsu(maxVal + 1);

        for (int num : nums) {
            if (num == 1) continue;
            vector<int> primes = getPrimes(num, spf);
            if (primes.empty()) continue;
            for (size_t i = 1; i < primes.size(); ++i) {
                dsu.unite(primes[i-1], primes[i]);
            }
            dsu.unite(num, primes[0]);
        }

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == sortedNums[i]) continue;
            if (dsu.find(nums[i]) != dsu.find(sortedNums[i])) {
                return false;
            }
        }
        return true;
    }
};