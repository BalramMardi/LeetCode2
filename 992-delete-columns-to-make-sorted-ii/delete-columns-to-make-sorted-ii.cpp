class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int deletionCount = 0;

        for (int j = 0; j < m; ++j) {
            bool deleteCol = false;
            for (int i = 0; i < n - 1; ++i) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    deleteCol = true;
                    break;
                }
            }

            if (deleteCol) {
                deletionCount++;
            } else {
                for (int i = 0; i < n - 1; ++i) {
                    if (strs[i][j] < strs[i + 1][j]) {
                        sorted[i] = true;
                    }
                }
            }
        }

        return deletionCount;
    }
};