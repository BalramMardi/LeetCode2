class Solution {
public:
    unordered_map<long long, double> memo;

    double dp(int row, int col, int poured) {
        if (col < 0 || col > row) return 0.0;         
        if (row == 0 && col == 0) return poured;      

        long long key = ((long long)row << 32) | col; 
        if (memo.count(key)) return memo[key];

        double left = (dp(row - 1, col - 1, poured) - 1.0) / 2.0;
        double right = (dp(row - 1, col, poured) - 1.0) / 2.0;

        if (left < 0) left = 0;
        if (right < 0) right = 0;

        return memo[key] = left + right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        return min(1.0, dp(query_row, query_glass, poured));
    }
};


/* class Solution {
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
}; */