class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> h(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
          
            for (int j = 0; j < m; j++) {
                h[j] = (mat[i][j] == 0 ? 0 : h[j] + 1);
            }

          
            stack<int> st;
            vector<int> sum(m, 0); 

            for (int j = 0; j < m; j++) {
                while (!st.empty() && h[st.top()] >= h[j]) {
                    st.pop();
                }

                if (!st.empty()) {
                    int prev = st.top();
                    sum[j] = sum[prev] + h[j] * (j - prev);
                } else {
                    sum[j] = h[j] * (j + 1);
                }

                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};




/* class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        vector<vector<int>> row(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    row[i][j] = mat[i][j];
                } else {
                    row[i][j] = (mat[i][j] == 0) ? 0 : row[i][j - 1] + 1;
                }
                int cur = row[i][j];
                for (int k = i; k >= 0; --k) {
                    cur = min(cur, row[k][j]);
                    if (cur == 0) {
                        break;
                    }
                    res += cur;
                }
            }
        }
        return res;
    }
}; */