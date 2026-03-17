
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> height(m, 0);
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            vector<int> temp = height;
            sort(temp.begin(), temp.end(), greater<int>());
            
            for(int j = 0; j < m; j++) {
                ans = max(ans, temp[j] * (j + 1));
            }
        }
        
        return ans;
    }
};