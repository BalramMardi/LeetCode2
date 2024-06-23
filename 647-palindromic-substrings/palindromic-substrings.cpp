class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        int count=0;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){

                if(g==0){
                    dp[i][j]=true;
                    count++;
                }
                else if(g==1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                        count++;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1]==true){
                        dp[i][j] = true;
                        count++;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return count;

    }
};