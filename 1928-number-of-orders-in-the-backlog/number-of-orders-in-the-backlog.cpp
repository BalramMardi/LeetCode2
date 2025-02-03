class Solution {
public:
    typedef pair<int,int> pp;
    
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int len = orders.size();
        const int MOD = 1e9 + 7;
        priority_queue<pp> buyHeap;
        priority_queue<pp,vector<pp>,greater<pp>> sellHeap;

        for(auto &order: orders){

            int price=order[0];
            int amount=order[1];
            int mode=order[2];

            //buy mode
            if(mode == 0){
                while(sellHeap.size() and sellHeap.top().first <= price and amount>0){
                    auto [sellPrice , sellAmount] = sellHeap.top();
                    sellHeap.pop();
                    int minAmount = min(amount,sellAmount);
                    sellAmount -= minAmount;
                    amount -= minAmount;
                    if(sellAmount > 0) sellHeap.push({sellPrice,sellAmount});
                }
                if(amount > 0) buyHeap.push({price,amount});
                
            }
            else{
                while(buyHeap.size() and buyHeap.top().first >= price and amount>0 and price>0){
                    auto [buyPrice , buyAmount] = buyHeap.top();
                    buyHeap.pop();
                    int minAmount = min(amount,buyAmount);
                    buyAmount -= minAmount;
                    amount -= minAmount;
                    if(buyAmount > 0) buyHeap.push({buyPrice,buyAmount});
                }
                if(amount > 0) sellHeap.push({price,amount});
            }

        }
        //agar abhi bhi backlog hai to count karlo

        long long backlog=0;
        while(buyHeap.size()){
            backlog = (backlog + buyHeap.top().second) % MOD;
            buyHeap.pop();
        }
        while(sellHeap.size()){
            backlog = (backlog + sellHeap.top().second) % MOD;
            sellHeap.pop();
        }

        return backlog;

        
    }
};