class Solution {
public:

    double champagneTower(int poured, int qRow, int qGlass) {
        
        vector<vector<double>> glasses(qRow+1,vector<double>(qRow+1));
        glasses[0][0]=poured;

        for(int row=0;row<qRow;row++){
            for(int glass=0;glass<=row;glass++){
                double overflow =double(glasses[row][glass]-1)/2.0;
                if(overflow>0){
                    glasses[row+1][glass]+=overflow;
                    glasses[row+1][glass+1] += overflow;
                }
            }
        }
        return min(1.0,glasses[qRow][qGlass]);

    }
};