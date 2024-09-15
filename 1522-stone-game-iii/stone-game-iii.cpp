class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& stone,int n,int idx){
        if(idx >= n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }


       int result = stone[idx]-solve(stone,n,idx+1);

        if(idx+1 < n)
            result = max(stone[idx]+stone[idx+1]-solve(stone,n,idx+2),result);
        
        if(idx+2 < n)
            result = max(stone[idx]+stone[idx+1]+stone[idx+2]-solve(stone,n,idx+3),result);

        return dp[idx]= result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        
        int n=stoneValue.size();
        dp.resize(n+1,-1);
        int diff = solve(stoneValue,n,0);
        if(diff > 0){
            return "Alice";
        }
        else if (diff<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }

};