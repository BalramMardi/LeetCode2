class Solution {
public:
    int m,n;
    int dp[501][501];
    int solve(string &s1,string &s2,int i,int j){
        if(i==m){
            return n-j;
        }
        else if(j==n){
            return m-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j]= solve(s1,s2,i+1,j+1);
        }
        else{
            int insert =1+ solve(s1,s2,i,j+1);
            int deleted =1+ solve(s1,s2,i+1,j);
            int replace =1+ solve(s1,s2,i+1,j+1);
            return dp[i][j] = min({insert,deleted,replace});
        }

        return -1;
    }


    int minDistance(string word1, string word2) {
        m=word1.size();
        n=word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);

    }
};