class Solution {
public:
const int INF = 1e8;
    int minDistance(vector<int>& h, int k) {
        int n=h.size();
        sort(h.begin(),h.end());
        vector<vector<int>> costs(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int mid = h[(i+j)/2];
                for(int x=i;x<=j;x++){
                    costs[i][j]+= abs(h[x]-mid);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for(int m=1;m<=k;m++){
            for(int i=1;i<=n;i++){
                for (int j = 0; j < i; j++) {   
                    if (dp[j][m - 1] != INF) {
                        dp[i][m] = min(dp[i][m], dp[j][m - 1] + costs[j][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];

    }
};