class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         int n = mat.size();
        int m = mat[0].size();

       
        unordered_map<int, pair<int, int>> positionMap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                positionMap[mat[i][j]] = {i, j};
            }
        }

       
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < arr.size(); i++) {
            auto pos = positionMap[arr[i]];
            int r = pos.first, c = pos.second;

            row[r]++;
            col[c]++;
            if (row[r] == m || col[c] == n) {
                return i;
            }
        }

        return -1; 
    }
};