class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        map<int,int> end_count;
        int end_of_brick, max_end_count=0;

        int rows = wall.size(),cols;

        for(int i =0;i<rows;i++){
            end_of_brick = 0;
            cols = wall[i].size() -1;
            for(int j =0;j<cols;j++){
                end_of_brick += wall[i][j];

                if(end_count.find(end_of_brick)!=end_count.end())
                {
                    end_count[end_of_brick]++;
                }
                else{
                    end_count[end_of_brick] = 1;
                }
                max_end_count = max(max_end_count,end_count[end_of_brick]);
            }
        }

        return rows - max_end_count;
    }
};