class Solution {
public:

   static bool comparator(const vector<int> &a ,const vector<int> &b){
        return (a[0]-a[1]) < (b[0]-b[1]);
    }


    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cost=0;
        int n = costs.size()/2;
        sort(costs.begin(),costs.end(),comparator);

        for(int i=0;i<n;i++){
            cost += costs[i][0] + costs[2*n-i-1][1];
        }
        return cost;
    }
};