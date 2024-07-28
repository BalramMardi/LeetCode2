#define ll long long

class Solution {
public:
    int mod = 1e9+7;
    int d[51][51][51];
    int solve(int i,int j,int m,int n,int mx){
        if(mx==0){
            if(i>=m || i<0 || j>=n || j<0){
                return 1;
            }

            return 0;
        }

        if(i>=m || i<0 || j>=n || j<0){
            return 1;
        }

        if(d[i][j][mx] != -1){
            return d[i][j][mx];
        }

        long long opt1=solve(i,j+1,m,n,mx-1);
        long long opt2=solve(i+1,j,m,n,mx-1);
        long long opt3=solve(i-1,j,m,n,mx-1);
        long long opt4=solve(i,j-1,m,n,mx-1);

        return d[i][j][mx] = (opt1+opt2+opt3+opt4)%mod;


    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(d,-1,sizeof(d));
        return solve(startRow,startColumn,m,n,maxMove);
    }
};