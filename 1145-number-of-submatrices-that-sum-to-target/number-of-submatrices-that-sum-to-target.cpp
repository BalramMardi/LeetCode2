class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m));

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum += matrix[i][j];
                mat[i][j] = sum;
            }
        }    

        int result = 0;
        for(int startCol = 0; startCol<m; startCol++) {
            
            for(int currCol = startCol; currCol<m; currCol++) {                
                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int row = 0; row<n; row++) {
                    sum += mat[row][currCol] - (startCol > 0 ? mat[row][startCol-1] : 0);
                    
                    if(mp.count(sum-target)) {
                        result += mp[sum-target];
                    }
                    
                    mp[sum]++;
                    
                }
                
            }
        }

        return result;
    }
};