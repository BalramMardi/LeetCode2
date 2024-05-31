class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub[9][9] = {false};

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.')
                    continue;

                int idx= board[r][c]-'0'-1;
                int area=(r/3)*3+(c/3);

                 if(row[r][idx] || col[c][idx] || sub[area][idx]){
                    return false;
                }
                row[r][idx] = true;
                col[c][idx] = true;
                sub[area][idx] = true;
            }
            
        }
        return true;
    }
};