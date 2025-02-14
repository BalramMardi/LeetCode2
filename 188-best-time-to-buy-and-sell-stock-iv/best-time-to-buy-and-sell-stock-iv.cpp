class Solution {
public:
    int dp[1001][101][2];
    int solver(vector<int>&prices, int i,int t,bool hold){

        if(i >= prices.size() or t==0){
            return 0;
        }

        if(dp[i][t][hold]!=-1){
            return dp[i][t][hold];
        }

        int doNothing = solver(prices,i+1,t,hold);

        if(hold){
            int sell = prices[i]+ solver(prices,i+1,t-1,0);
            return dp[i][t][hold] = max(sell, doNothing);
        }
        else{
            int buy = -prices[i]+solver(prices,i+1,t,1);
            return dp[i][t][hold] = max(buy,doNothing);
        }


    }




    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solver(prices,0,k,0);
    }
};