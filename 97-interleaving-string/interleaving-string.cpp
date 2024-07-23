class Solution {
public:

    int memo[101][101][201];
    bool solve(string &s1,string &s2,string &s3,int i, int j,int k){
        if(i==s1.length() && j==s2.length() && k==s3.length()){
            return true;
        }
        if(k>=s3.length()){
            return false;
        }

        if(memo[i][j][k] != -1){
            return memo[i][j][k];
        }

        bool result=false;

        if(s1[i] == s3[k]){
            result= solve(s1,s2,s3,i+1,j,k+1);
        }

        if(result){
            return memo[i][j][k] = result;
        }
        
        if(s2[j] == s3[k]){
            result= solve(s1,s2,s3,i,j+1,k+1);
        }

        return memo[i][j][k]= result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        memset(memo,-1,sizeof(memo));
        return solve(s1,s2,s3,0,0,0);
    }
};