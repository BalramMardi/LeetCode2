class Solution {
public:
    int memo[5001][2];
    int solve(vector<int>& prices,int idx,bool buy){
        if(idx >= prices.size()){
            return 0;
        }
        
        if(memo[idx][buy] != -1 ){
            return memo[idx][buy];
        }

        int profit=0;
        if(buy){
            int take = solve(prices,idx+1,false) - prices[idx];
            int skip = solve(prices,idx+1,true);

            profit = max({profit,take,skip});
        }
        else{
            int sell = solve(prices,idx+2,true) + prices[idx];
            int not_sell = solve(prices,idx+1,false);

            profit = max({profit,sell,not_sell});
        }

        return  memo[idx][buy]= profit;
    }


    int maxProfit(vector<int>& prices) {

        memset(memo,-1,sizeof(memo));
        bool buy=true;
        return solve(prices,0,buy);
    }
};