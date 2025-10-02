class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int top = 0, left = 0;
        int bottom = (int)matrix.size() - 1;
        int right = (int)matrix[0].size() - 1;
        vector<int> res;
        res.reserve((bottom + 1) * (right + 1));

        while (top <= bottom && left <= right) {
            // move right across top row
            for (int j = left; j <= right; ++j) res.push_back(matrix[top][j]);
            ++top;
            if (top > bottom) break;

            // move down right column
            for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
            --right;
            if (left > right) break;

            // move left across bottom row
            for (int j = right; j >= left; --j) res.push_back(matrix[bottom][j]);
            --bottom;
            if (top > bottom) break;

            // move up left column
            for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
            ++left;
        }

        return res;
    }
};