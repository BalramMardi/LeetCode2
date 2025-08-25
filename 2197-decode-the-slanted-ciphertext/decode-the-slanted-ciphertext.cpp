class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (n == 0) return "";

        int cols = n / rows;
        vector<vector<char>> grid(rows, vector<char>(cols));

        int idx = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                grid[r][c] = encodedText[idx++];
            }
        }

        string ans;
        for (int start = 0; start < cols; start++) {
            int r = 0, c = start;
            while (r < rows && c < cols) {
                ans.push_back(grid[r][c]);
                r++;
                c++;
            }
        }

        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};