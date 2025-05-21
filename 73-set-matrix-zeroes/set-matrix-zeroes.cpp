class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vec.push_back({i,j});
                }
            }
        }


        for(int i=0;i<vec.size();i++){
            for(int j=0;j<m;j++){
                matrix[vec[i].first][j] =0;
            }

            for(int k=0;k<n;k++){
                matrix[k][vec[i].second]=0;
            }
        }
        
    }
};