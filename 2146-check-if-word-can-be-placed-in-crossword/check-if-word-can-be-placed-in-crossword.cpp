class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int size;
    int n,m;
    int solve(string word,vector<vector<char>>& b,int i,int j,int idx,int d)
    {
        if(idx==size)
        {
            int ni = i;
            int nj = j;
            if(ni>=0 and ni<n and nj>=0 and nj<m)
            {
                if(b[ni][nj]==' ' or b[ni][nj]!='#')
                    return 0;
            }
            return 1;
        }
        
        if(b[i][j]==' ' or b[i][j]==word[idx])
        {
            if(solve(word,b,i+dir[d][0],j+dir[d][1],idx+1,d))
                return 1;
        }
    
        return 0;
    }
    bool placeWordInCrossword(vector<vector<char>>& b, string word) 
    {
        n = b.size();
        m = b[0].size();
        size = word.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i][j]!='#')
                {
                    int idx = 0;
                    if(i+1-size>=0 and (i==n-1 or b[i+1][j]=='#'))//up
                    {
                        // cout<<"here "<<i<<" "<<j<<endl;
                        if(solve(word,b,i,j,idx,0))
                        return true;
                    }
                    if((n-i)-size>=0 and (i==0 or b[i-1][j] == '#'))//down
                    {
                        // cout<<"here1 "<<i<<" "<<j<<endl;
                        
                        if(solve(word,b,i,j,idx,1))
                        return true;
                    }
                    if(j+1-size>=0 and (j==m-1 or b[i][j+1]=='#'))//left
                    {
                        // cout<<"here2 "<<i<<" "<<j<<endl;
                        
                        if(solve(word,b,i,j,idx,2))
                        return true;
                    }
                    if((m-j)-size>=0 and (j==0 or b[i][j-1]=='#'))//right
                    {
                        // cout<<"here3 "<<i<<" "<<j<<endl;
                        
                        if(solve(word,b,i,j,idx,3))
                        return true;
                    }
                }
            }
        }
        return false;
    }
};