class Solution {
public:

    typedef long long ll;

    ll dp[5001][4][4][4];
    int mod = 1e9+7;
    int N;
    vector<int> choice = {1,2,3};

    ll solve(int idx, int p1, int p2, int p3){

        if(idx==N){
            return 1;
        }

        if(dp[idx][p1][p2][p3] != -1){
            return dp[idx][p1][p2][p3];
        }

        ll count=0;
        
        for(int &c1 : choice){

            if(c1==p1) continue;

            for(int &c2 : choice){

                if(c2==p2 || c2==c1) continue;

                for(int &c3 : choice){

                    if(c3==p3 || c3==c2) continue;

                    count += solve(idx+1,c1,c2,c3) % mod;

                }

            }

            
        }

        return dp[idx][p1][p2][p3] = count%mod;
    }

    int numOfWays(int n) {
        N=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,0);
    }
};