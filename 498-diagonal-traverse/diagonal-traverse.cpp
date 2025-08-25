class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, vector<int>> groups;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                groups[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        ans.reserve(m * n);

        for (int d = 0; d <= m + n - 2; d++) {
            if (d % 2 == 0) {
                reverse(groups[d].begin(), groups[d].end());
            }
            for (int val : groups[d]) ans.push_back(val);
        }

        return ans;
    }
};