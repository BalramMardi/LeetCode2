class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        map<long long,int> end_count;
        long long end_of_brick; int max_end_count=0;

        int rows = wall.size(),cols;

        for(int i =0;i<rows;i++){
            end_of_brick = 0;
            cols = wall[i].size() -1;
            for(int j =0;j<cols;j++){
                end_of_brick += wall[i][j];

                 end_count[end_of_brick]++;
                
                max_end_count = max(max_end_count,end_count[end_of_brick]);
            }
        }

        return rows - max_end_count;
    }
};