class Solution {
public:
    int memo[301][5001];
    int solve(vector<int>& coins,int total,int idx){
        if(total < 0 or idx>=coins.size()){
            return 0;
        }

        if(total == 0){
            return 1;
        }

        if(memo[idx][total] != -1){
            return memo[idx][total];
        }

        

        int take = solve(coins,total-coins[idx],idx);
        int skip = solve(coins,total,idx+1);

        return  memo[idx][total]= take+skip;


    }


    int change(int amount, vector<int>& coins) {
        memset(memo,-1,sizeof(memo));
        return solve(coins,amount,0);
    }
};