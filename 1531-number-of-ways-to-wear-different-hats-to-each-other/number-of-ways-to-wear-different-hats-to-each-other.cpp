class Solution {
public:

    const int mod = 1e9+7;

    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> htp(41);
        int n=hats.size();
        for(int i=0;i<n;i++){
            for(int hat: hats[i]){
                htp[hat].push_back(i);
            }
        }

        vector<int> dp(1<<n,0);
        dp[0]=1;

        for(int h=1;h<41;h++){
            vector<int> new_dp(1<<n,0);
            for(int mask=0;mask<(1<<n);mask++){
                if(dp[mask]){
                    new_dp[mask] = (dp[mask] + new_dp[mask]) % mod;
                    for(int person : htp[h]){

                        if((mask & (1 << person)) == 0){
                            int new_mask = (mask | (1 << person));
                            new_dp[new_mask] = (new_dp[new_mask]+dp[mask]) % mod;
                        }

                    }
                }
            }

            dp=new_dp;
        }


        return dp[(1<<n)-1];
    }
};