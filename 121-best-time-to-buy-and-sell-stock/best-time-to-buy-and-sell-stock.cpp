class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int lsf=INT_MAX;
        int pist=0;
        int op=0;

        for(int i=0;i<prices.size();i++){
            if(lsf > prices[i]){
                lsf = prices[i];
            }

            lsf = min(lsf, prices[i]);

            pist = prices[i]-lsf;

            op = max(op,pist);

        }
        return op;
    }
};