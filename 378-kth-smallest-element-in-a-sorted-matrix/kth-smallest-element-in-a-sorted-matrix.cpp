class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for(int i = 0; i < n; i++) pq.push({matrix[i][0], i, 0});

        int ans = -1;
        while(k--) {
            auto [val, r, c] = pq.top(); pq.pop();
            ans = val;
            if(c+1 < n) pq.push({matrix[r][c+1], r, c+1});
        }
        return ans;
    }
};