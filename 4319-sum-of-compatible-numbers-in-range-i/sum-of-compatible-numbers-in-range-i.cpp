class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int f = max(1,n-k);
        int r = n+k;
        int sum=0;
        for(int i=f;i<=r;i++){
            if((n & i) == 0){
                sum += i;
            }
        }
        return sum;
    }
};