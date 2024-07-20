class Solution {
public:
    int memo[1001][1001];
    int dfs(string &text1,string &text2,int i,int j){
        if(i>=text1.length() || j>=text2.length()){
            return 0;
        }


         if(memo[i][j]!=-1){
            return memo[i][j];
        }

        if(text1[i] == text2[j]){
            return memo[i][j]= 1 + dfs(text1,text2,i+1,j+1);
        }

        return  memo[i][j]=max(dfs(text1,text2,i,j+1),dfs(text1,text2,i+1,j));
    }

    int longestCommonSubsequence(string text1, string text2) {

        memset(memo,-1,sizeof(memo));
        return dfs(text1,text2,0,0);
    }
};