class Solution {
public:
    const int MOD=1e9 + 7;
    int memo[100001];

    int solve(int low,int high,int zero,int one,int length){
        if(length > high){
            return 0;
        }

        if(memo[length]!=-1){
            return memo[length];
        }
        int flag = false;

        if(length<=high and length>=low){
            flag=true;
        }

        int take_one = solve(low,high,zero,one,length+one);
        int take_zero = solve(low,high,zero,one,length+zero);

        return  memo[length] = (flag + take_one+take_zero)%MOD;

    }

    int countGoodStrings(int low, int high, int zero, int one) {
        memset(memo,-1,sizeof(memo));
        int ans = solve(low,high,zero,one,0);
        return ans;
    }
};