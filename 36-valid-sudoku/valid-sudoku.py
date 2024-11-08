class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[False] * 9 for _ in range(9)]
        col = [[False] * 9 for _ in range(9)]
        sub = [[False] * 9 for _ in range(9)]

        for r in range(len(board)):
            for c in range(len(board[0])):
                if(board[r][c] == '.'):
                    continue
                idx = int(board[r][c])-1
                area = (r//3)*3 + (c//3)

                if(row[r][idx] or col[c][idx] or sub[area][idx]):
                    return False
                
                row[r][idx] = True
                col[c][idx] = True
                sub[area][idx] = True

        return True

