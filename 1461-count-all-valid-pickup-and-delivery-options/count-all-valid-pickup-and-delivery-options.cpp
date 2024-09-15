class Solution {
public:
    int MOD = 1e9+7;
    int countOrders(int n) {
        if(n==1){
            return 1;
        }
        long long result = 1;
        for(int i=2;i<=n;i++){

            int spaces = 2*(i-1)+1;
            int poss = (spaces * (spaces+1))/2;

            result *= poss;

            result %= MOD;
            
        }

        return result;
    }
};