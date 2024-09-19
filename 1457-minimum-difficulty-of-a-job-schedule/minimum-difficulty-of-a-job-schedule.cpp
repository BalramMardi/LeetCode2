class Solution {
public:
    int n;
    int dp[301][11];
    int solve(vector<int>&job,int d,int idx){
        
        if(dp[idx][d]!=-1){
            return dp[idx][d];
        }
        if(d==1){
            int maxD = job[idx];

            for(int i=idx;i<n;i++){
                maxD = max(maxD,job[i]);
            }
            return dp[idx][d]= maxD;
        }

        int maxD = job[idx];
        int res,final=INT_MAX;

        for(int i=idx;i<=n-d;i++){
            maxD = max(maxD,job[i]);
            res = maxD + solve(job,d-1,i+1);
            final = min(final,res);
        }

        return dp[idx][d]= final;
    }


    int minDifficulty(vector<int>& job, int d) {
        n = job.size();
        memset(dp,-1,sizeof(dp));
        if(n < d){
            return -1;
        }
        return solve(job,d,0);
    }
};