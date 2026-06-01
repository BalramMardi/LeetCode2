class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int sum=0;
        int k=1;
        for(int i=cost.size()-1;i>=0;i--){
            if(k==3){
                k=1;
                continue;
            }
            sum += cost[i];
            k++;
        }
        return sum;
    }
};