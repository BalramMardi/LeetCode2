class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());

        long long curr=0;
        int cnt=0;

        for(int it : costs){
            curr += it;

            if(curr <= coins){
                cnt++;
            }
            else {
                break;
            }
        }
        return cnt;
    }
};